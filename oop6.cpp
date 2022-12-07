#include <iostream>
using T = int;
template<typename T>
class queue 
{
public:
	queue();
	~queue();
	void push(T data);
	int getsize() { return size; }
	void pop();
	void clear();
	void removeat(int index);
	void print();
	bool empty();
	T front();
	T back();

private:
	template<typename T>
	class Node {
	public:
		Node *pnext;
		Node* pprev;
		T data;
		Node(T data = T(), Node* pnext = nullptr, Node* pprev = nullptr) {
			this->data = data;
			this->pnext = pnext;
			this->pprev = pprev;
		}
	};
	Node<T>* head;
	Node<T>* end;
	int size;
};
template<typename T>
queue<T>::queue() {
	size = 0;
	head = nullptr;
	end = nullptr;
}
template<typename T>
queue<T>::~queue() {
	clear();
}
template<typename T>
void queue<T>::push(T data) {
	if (head == nullptr) {
		head = new Node<T>(data);
	}
	else {
		Node<T>* current = this->head;
		while (current->pnext != nullptr) { current = current->pnext; }
		current->pnext = new Node<T>(data);
		end = current->pnext;

	}
	size++;
}
template<typename T>
void queue<T>::pop() {
	Node<T> *temp = this->head;
	head = head->pnext;
	delete temp;
	size--;
}
template<typename T>
void queue<T>::clear() {
	while (size) {
		pop();
	}
}
template<typename T>
void queue<T>::removeat(int index) {
	if (index == 0) { pop(); }
	else {
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++) {
			previous = previous->pnext;
		}
		Node<T>* toDelete = previous->pnext;
		previous->pnext = toDelete->pnext;
		delete toDelete;
		size--;
	
	}
}
template<typename T>
void queue<T>::print() {

	Node<T>* current = this->head;
	while (current) {
		std::cout << current->data << "  ";
		current = current->pnext;
	}
}
template<typename T>
bool queue<T>::empty() {
	return head == nullptr;
}
template<typename T>
T queue<T>::front() {
	return head->data;
}
template<typename T>
T queue<T>::back() {
	Node<T>* temp = this->head;
	while (temp->pnext) { temp = temp->pnext; }
	end = temp;
	return end->data;
}
int main() {

	enum actions {
		push, getsize, pop, front, back, clear, print, empty, endsession
	};

	bool stop = false;
	int choice;

	queue<int>lst;
	std::cout << "Enter size of queue :\n";
	int numberscount;
	std::cin >> numberscount;
	for (int i = 0; i < numberscount; i++) {
		lst.push(rand() % 99 + 1);
	}
	std::cout << " queue created!\n";

	std::cout << " 0 - push  1 - getsize  2 - pop  3 - front  4 - back  " << std::endl;
	std::cout << " 5 - clear  6 - print  7 - empty  8 - endsession  " << std::endl;
	while (!stop) {
		std::cout << "\nselect action : ";
		std::cin >> choice;
		switch (choice) {
		case actions::empty:
			if (lst.empty()) { std::cout << "queue is empty\n"; }
			else { std::cout << "queue is not empty \n"; }
			break;
		case actions::front:
			std::cout << "first element queue : " << lst.front() << std::endl;
			break;
		case actions::back:
			std::cout << "last element queue : " << lst.back() << std::endl;
			break;
		case actions::print:
			lst.print();
			std::cout << std::endl;
			break;
		case actions::getsize:
			std::cout << "size of queue = " << lst.getsize() << std::endl;
			break;
		case actions::push:
			int elemb;
			std::cout << "enter element which you want to add :";
			std::cin >> elemb;
			lst.push(elemb);
			break;
		case actions::pop:
			lst.pop();
			std::cout << "first element has been removed\n";
			break;
		case actions::clear:
			lst.clear();
			std::cout << "the queue has been removed\n";
			break;
		case actions::endsession:
			std::cout << "cya!";
			stop = true;
			break;
		}	
	}
}



