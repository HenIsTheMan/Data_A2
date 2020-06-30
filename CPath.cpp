#include "CPath.h"

CPath::CPath(): head(0), in(0){}

CPath::~CPath(){
	while(head->getNext() != 0){
		head = head->getNext();
		delete head->getPrev();
	}
	delete head;
}

void CPath::addNode(){
	CNode* newNode = new CNode;
	if(in->getCh() != 'E'){
		newNode->setCh('w');
		in->getNext()->setPrev(newNode);
		newNode->setNext(in->getNext());
	} else{
		in->setCh('o');
		newNode->setCh('E');
	}
	in->setNext(newNode);
	newNode->setPrev(in);
}

void CPath::deleteNode(){
	if((in->getCh() == 'S' && in->getNext()->getCh() == 'E') || (in->getCh() == 'E' && in->getPrev()->getCh() == 'S')){
		return;
	}
	if(in->getCh() == 'S'){
		in = in->getNext();
		head = in;
		delete in->getPrev();
		in->setPrev(0);
		in->setCh('S');
	} else if(in->getCh() == 'E'){
		in = in->getPrev();
		delete in->getNext();
		in->setNext(0);
		in->setCh('E');
	} else{
		CNode* temp = in;
		in->getNext()->setPrev(in->getPrev());
		in->getPrev()->setNext(in->getNext());
		in = in->getNext();
		delete temp;
	}
}

void CPath::engageUser(){
	short choice;
	while(1){
		cout << "Choose ---> Bck(1), Fwd(2), AddNode(3), DelNode(4): ";
		cin >> choice;
		if(choice < 1 || choice > 4){
			break;
		}
		if(choice == 1 && in->getPrev() != 0){
			in = in->getPrev();
		} else if(choice == 2 && in->getNext() != 0){
			in = in->getNext();
		} else if(choice == 3){
			addNode();
		} else if(choice == 4){
			deleteNode();
		}
		system("cls");
		print();
	}
}

void CPath::print() const{
	printf("%s\n%s\n", "1-2-3-4-5-6-7-8-9-0-1-2-3-4-5-6-7-8-9-0", "---------------------------------------");
	bool type = 1;
	short count = 0;
	CNode *cur1 = head, *cur2 = head;
	while(cur2 != 0){
		if(type){
			cout << (count == 0 ? "" : "-") << cur1->getCh();
			if(cur1->getNext() != 0){
				cur1 = cur1->getNext();
			} else{
				count = 19;
			}
		} else{
			cout << (cur2 == in ? "^" : "  ");
			cur2 = cur2->getNext();
			if(cur2 == 0){
				break;
			}
		}
		++count;
		if(count == 20){
			cout << endl;
			type = !type;
			count = 0;
		}
	}
	cout << endl;
}

void CPath::start(){
	for(short i = 0; i < 50; ++i){
		head = in;
		in = new CNode;
		if(i % 49 == 0){
			in->setCh(i == 0 ? 'E' : 'S');
		}
		if(i != 0){
			head->setPrev(in);
			in->setNext(head);
		}
	}
	head = in;
	print();
}