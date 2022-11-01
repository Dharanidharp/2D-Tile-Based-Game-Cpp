//#include "../../include/utils/Subject.h"
//
//void Subject::addObserver(Observer* observer) 
//{
//	observer->prev = nullptr;
//	observer->next = head;
//	head = observer;
//	if (observer->next)
//		observer->next->prev = observer;
//}
//
//void Subject::removeObserver(Observer* observer) 
//{
//	if (observer->prev)
//		observer->prev->next = observer->next;
//
//	if (observer->next)
//		observer->next->prev = observer->prev;
//
//	if (head == observer)
//		head = observer->next;
//}
//
//void Subject::notify(const Entity& entity, Event event) 
//{
//	Observer* current = head;
//	while (current != nullptr) 
//	{
//		current->onNotify(entity, event);
//		current->next;
//	}
//}