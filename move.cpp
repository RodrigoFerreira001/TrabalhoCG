#include "move.hpp"

Move::Move(int type, int axis, float value){
	this->type = type;
	this->axis = axis;
	this->value = value;
}
