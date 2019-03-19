// South Hills IT213, Fall 2018
// Created by Chris Coble on 10/8/2018
//
// Implement a customer queue using a doubly linked list.
//

#include "stdafx.h"
#include <iostream>
#include <string>

struct Person {
	std::string fname;
	std::string lname;
	Person* next;
	Person* prev;
};

struct Queue {
	Person* front;
	Person* back;
};

void printQueue(Queue* q) {
	Person* p = q->front;

	std::cout << "Current queue:\n";
	while (p != NULL) {
		std::cout << p->fname << " " << p->lname << std::endl;
		p = p->prev;
	}
	std::cout << std::endl;
}

void addCustomer(Queue* q, std::string fname, std::string lname) {
	Person* person = new Person;
	person->fname = fname;
	person->lname = lname;
	person->next = q->back;
	person->prev = NULL;

	// Update back of queue's prev pointer only if
	// queue is not empty!!
	if (q->back != NULL) {
		q->back->prev = person;
	}

	q->back = person;

	// Update front of queue if queue was empty!!
	if (q->front == NULL) {
		q->front = person;
	}
}

void nextCustomer(Queue* q) {
	if (q->front == NULL) {
		std::cout << "There are no more customers in the queue!\n";
		return;
	}

	std::cout << "Next customer is " << q->front->fname << " " << q->front->lname << std::endl;
	Person* tmp = q->front;
	q->front = q->front->prev;

	// update front of queue's next pointer only if the
	// queue is not empty!!
	if (q->front != NULL) {
		q->front->next = NULL;
	}
	else {
		// set back of queue to NULL if queue becomes empty!!
		q->back = NULL;
	}

	delete tmp;
}

void removeCustomer(Queue* q, std::string fname, std::string lname) {
	Person* p = q->front;

	// search the queue for person with matching name
	while (p != NULL) {
		if (p->fname == fname && p->lname == lname) {
			break;
		}
		p = p->prev;
	}

	if (p == NULL) {
		std::cout << "No customer by the name of " << fname << " " << lname << std::endl;
		return;
	}

	if (p->next != NULL) {
		p->next->prev = p->prev;
	}
	else {
		// removing first person in the queue
		q->front = p->prev;
	}

	if (p->prev != NULL) {
		p->prev->next = p->next;
	}
	else {
		// removing last person in the queue
		q->back = p;
	}

	std::cout << "Removed " << p->fname << " " << p->lname << std::endl;

	delete p;
}

// delete any remaining people in the que
void clearQueue(Queue* q) {
	Person* p = q->front;
	while (p != NULL) {
		Person* tmp = p;
		p = p->prev;
		delete tmp;
	}

	// make queue empty
	q->front = NULL;
	q->back = NULL;
}

int main()
{
	Queue* q = new Queue;
	q->back = NULL;
	q->front = NULL;

	addCustomer(q, "Aaron", "I");
	addCustomer(q, "Brennan", "D");
	addCustomer(q, "Heidi", "M");
	addCustomer(q, "Chris", "C");
	addCustomer(q, "Lev", "T");
	addCustomer(q, "Spencer", "B");
	addCustomer(q, "Roman", "N");
	printQueue(q);

	// Next customer should be Aaron
	nextCustomer(q);
	printQueue(q);

	// Remove Lev from Middle
	removeCustomer(q, "Lev", "T");
	printQueue(q);

	// Remove Non-existing customer
	removeCustomer(q, "Eric", "C");
	printQueue(q);

	// Remove Brennan from Front
	removeCustomer(q, "Brennan", "D");
	printQueue(q);

	// Remove Roman from Back
	removeCustomer(q, "Roman", "N");
	printQueue(q);

	// Heidi, Chris, Spencer
	nextCustomer(q);
	printQueue(q);
	nextCustomer(q);
	printQueue(q);
	nextCustomer(q);
	printQueue(q);

	// No more customers
	nextCustomer(q);

	clearQueue(q);
	delete q;
}