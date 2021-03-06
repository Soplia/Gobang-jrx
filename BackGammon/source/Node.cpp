/*!
 @author Created by Jiarui XIE on 2019/2/7
 
 COMPLIER: Xcode - Version 9.0 beta 3
 
 Copyright © 2019 QM. All rights reserved.
 */

#include "Node.hpp"
/*!
 *@brief   A constructor.
 */
Node::Node()
{
   _bestChild = nullptr;
   _child = new vector<Node*>();
   _child -> clear();
   _mark = 0;
}

/*!
 *@brief   A copy constructor.
 *
 *@param    other    the parameter
 */
Node::Node(const Node &other)
{
   _mark = other._mark;
   _point.SetXY(other._point._x, other._point._y);
   _bestChild = new Node();
   _bestChild = other._bestChild;
   _child = new vector<Node*>;
   _child -> clear();
   for (int i = 0; i < other._child -> size(); i++)
      _child -> push_back(other._child -> at(i));
}

/*!
 *@brief   Operator =
 *
 *@param    other    the parameter used to assignment
 */
Node & Node::operator = (const Node & other)
{
   if (this == &other)
      return *this;
   
   delete _bestChild;
   delete _child;
   
   _mark = other._mark;
   _point.SetXY(other._point._x, other._point._y);
   _bestChild = new Node();
   _bestChild = other._bestChild;
   _child = new vector<Node*>;
   _child -> clear();
   for (int i = 0; i < other._child -> size(); i++)
      _child -> push_back(other._child -> at(i));
   
   return *this;
}

/*!
 *@brief   A setor
 *
 *@param    p    set p to the member of Node
 */
void Node::SetPoint(Position p)
{
   _point._x = p._x;
   _point._y = p._y;
}

/*!
 *@brief   Add the node into the verctor _child.
 *
 *@param    r    the node which is going to be added into _child.
 */
void Node::AddChild(Node *r)
{
   _child -> push_back(r);
}

/*!
 *@brief   Get the last child.
 *
 *@return   the last object in _child.
 */
Node * Node::GetLastChild()
{
   //这个地方有问题那就进行尝试而已
   return  _child -> at(_child -> size() - 1);
}


