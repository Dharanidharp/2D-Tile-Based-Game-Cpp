#include "../../include/core/Game.h"
#include "../../include/entities/Fire.h"
#include "../../include/entities/StaticEntities.h"
#include "../../include/core/Command.h"
#include "../../include/systems/Systems.h"
#include "../../include//utils/SoundPlayer.h"
#include "../../include//utils/ServiceLocator.h"
#include "../../include/entities/EntityPool.h"
#include <iostream>
#include <functional>

using OnCollisionCallback = std::function<void(float)>;

// III.F Add the initialization (to 0) of the entity counter to the initalizers list of this constructor
Game::Game() : paused(false), entityID(0), inputHandler{ std::make_unique<InputHandler>() }
{
	logicSystems.push_back(std::make_shared<TTLSystem>());
	logicSystems.push_back(std::make_shared<InputSystem>());
	logicSystems.push_back(std::make_shared<MovementSystem>());
	graphicSystem.push_back(std::make_shared<GraphicsSystem>());
	logicSystems.push_back(std::make_shared<ColliderSystem>());
	logicSystems.push_back(std::make_shared<GameplaySystem>());

	SoundPlayer *soundPlayer = new SoundPlayer();
	ServiceLocator::RegisterServiceLocator(soundPlayer);
}

Game::~Game()
{
}

template <typename T>
std::shared_ptr<T> Game::buildEntityAt(const std::string& filename, int col, int row)
{
	auto ent = std::make_shared<T>();
	float x = col * spriteWH * tileScale;
	float y = row * spriteWH * tileScale;
	float cntrFactor = (tileScale - itemScale) * spriteWH * 0.5f;
	dynamic_cast<PositionComponent*>(ent->getComponentID(ComponentID::POSITION))->setPosition(x + cntrFactor, y + cntrFactor);
	
	ent->init(true, filename, std::make_shared<SimpleSpriteGraphics>(itemScale));
	
	return ent;
}

void Game::buildBoard(int width, int height)
{
	board = std::make_unique<Board>(width, height);
}

void Game::initWindow(int width, int height)
{
	int wdt = static_cast<int>(width * spriteWH * tileScale);
	int hgt = static_cast<int>(height * spriteWH * tileScale);
	window.setSize(sf::Vector2u(wdt, hgt));
	window.redraw();
}

void Game::init(std::vector<std::string> lines)
{
	int h = lines.size() - 1;
	if (h < 0)
		throw std::exception("No data in level file");
	int w = -1;

	// Load the font for the window and set its title
	window.loadFont("font/AmaticSC-Regular.ttf");
	window.setTitle("Mini-Game");
	
	auto it = lines.cbegin();
	int row = 0;
	while (it != lines.cend())
	{
		int col = 0;

		// First iteration: we determine the width of the level (w) by the number of symbols in the first line.
		if(w == -1)
		{
			//The size of the window must be equal to the number of tiles it has, factoring their dimensions.
			w = it->size();
			buildBoard(w, h);
			initWindow(w, h);		
		}
		
		std::string::const_iterator is = it->cbegin();
		while (is != it->cend())
		{
			switch (*is)
			{
			case '.':
			{
				board->addTile(col, row, tileScale, TileType::CORRIDOR);
				break;
			}
			case 'w':
			{
				board->addTile(col, row, tileScale, TileType::WALL);
				break;
			}
			case 'x':
			{
				auto logPtr{ buildEntityAt<Log>("img/log.png", col, row) };
				addEntity(logPtr);
				logPtr->setUseBool(true);
	
				board->addTile(col, row, tileScale, TileType::CORRIDOR);
				break;
			}
			case 'p':
			{
				auto potionPtr{ buildEntityAt<Potion>("img/potion.png", col, row) };
				addEntity(potionPtr);
				potionPtr->setUseBool(true);
	
				board->addTile(col, row, tileScale, TileType::CORRIDOR);
				break;
			}
			case '*':
				{
				player = std::make_shared<Player>();

				player->init("img/DwarfSpriteSheet_data.txt", std::make_shared<SpriteSheetGraphics>());

				player->positionSprite(row, col, spriteWH, tileScale);

				addEntity(player);

				board->addTile(col, row, tileScale, TileType::CORRIDOR);
				break;
				}
			}

			col++; is++;
		}
		row++; it++;
	}
}

void Game::addEntity(std::shared_ptr<Entity> newEntity)
{
	entityID++;
	newEntity->setID(entityID);
	entities.push_back(newEntity);
}

void Game::handleInput()
{
	auto command = inputHandler->handleInput();
	if (command)
		command->execute(*this);
}


void Game::update(float elapsed)
{
	// V.E Only update the game entities if the game is not paused.
	if (!isPaused())
	{
		bigArray(logicSystems, elapsed);

		auto it = entities.begin();

		while (it != entities.end()) 
		{
			EntityType entityType = (*it)->getEntityType();

			if (entityType != EntityType::PLAYER && entityType != EntityType::FIRE && player->collision(*(*it)))
			{
				switch (entityType)
				{
					// IX.H: This is a potion
				case EntityType::POTION: 
				{
					if ((*it)->inUse()) 
					{
						/*std::function<void(float)> func = std::bind(&Player::collision, (*it), std::placeholders::_1)
						player->registerPotionCallback((*it)->getID(), func);*/

						int health = dynamic_cast<Potion*>((*it).get())->getHealth();
						auto healthComponent = dynamic_cast<HealthComponent*>(player->getComponentID(ComponentID::HEALTH));
						healthComponent->changeHealth(health);

						AudioManager* audio = ServiceLocator::GetAudio();
						audio->PlaySound("sounds/pickup.wav");


						std::cout << "Restored health: " << health << std::endl;
						std::cout << "Current health: " << healthComponent->getHealth() << std::endl;

						(*it)->setUseBool(false);
					}
					break;
				}
				// IX.I: This is a log
				case EntityType::LOG:
				{
					if ((*it)->inUse()) 
					{
						/*std::function<void(float)> func = std::bind(&Player::registerLogCallback, (*it), std::placeholders::_1);
						player->registerLogCallback((*it)->getID(), func);*/

						if (dynamic_cast<GraphicsComponent*>(player->getComponentID(ComponentID::GRAPHICS))->isInAction())
						{
							int wood = dynamic_cast<Log*>((*it).get())->getWood();
							player->addWood(wood);

							std::cout << "Wood collected: " << wood << std::endl;
							std::cout << "Current wood: " << player->getWood() << std::endl;
							(*it)->setUseBool(false);
						}
					}

					break;
				}
				default:
					break;
				}
			}
			it++;
		}

		it = entities.begin();
		while (it != entities.end())
		{
			if ((*it)->isDeleted())
				it = entities.erase(it);
			else
				it++;
		}

		window.update();
	}
}

void Game::render(float elapsed)
{
	//Empty the screen
	window.beginDraw();

	// II.D Call the draw method of the board object passing a pointer of the window.
	board->draw(&window);
	bigArray(graphicSystem, elapsed);

	//Draw FPS
	window.drawGUI(*this);

	//Close up for this frame.
	window.endDraw();
}


sf::Time Game::getElapsed() const { return gameClock.getElapsedTime(); }


void Game::setFPS(int FPS)
{
	std::string text("FPS: " + std::to_string(FPS));
	window.getFPSText().setString(text);
}

// III.G Return the current ID counter.
const EntityID& Game::getIDCounter() const
{
	return entityID;  //you can delete this once III.G is complete.
}

const std::shared_ptr<Entity>& Game::getEntity(unsigned int idx) const
{
	if (idx >=0 && idx < entities.size()) 
	{
		return entities.at(idx);
	}
	else 
	{
		throw std::runtime_error("Entity Error");
	}
}

void Game::bigArray(std::vector<std::shared_ptr<System>> sys, float elapsed)
{
	auto sysIt = sys.begin();

	while (sysIt != sys.end())
	{
		auto entIt = entities.begin();

		while (entIt != entities.end())
		{
			if (!(*entIt)->isDeleted() && (*sysIt)->validate(entIt->get()))
			{
				(*sysIt)->update(this, entIt->get(), elapsed);
			}

			entIt++;
		}

		sysIt++;
	}
}
