#include "CNode.h"

CNode::CNode(): ch('o'), prev(0), next(0){}

char CNode::getCh() const{
	return ch;
}

CNode* CNode::getPrev() const{
	return prev;
}

CNode* CNode::getNext() const{
	return next;
}

void CNode::setCh(char c){
	ch = c;
}

void CNode::setPrev(CNode* p){
	prev = p;
}

void CNode::setNext(CNode* n){
	next = n;
}