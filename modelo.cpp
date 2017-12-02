#include "modelo.hpp"

Modelo::Modelo(){
	this->largura = 0.0f;
	this->altura = 0.0f;
	this->profundidade = 0.0f;
	this->rotacao = 0.0f;
	this->deslocamento_x = 0.0f;
	this->deslocamento_y = 0.0f;
	this->deslocamento_z = 0.0f;
}

Modelo::Modelo(float largura){
	this->largura = largura;
	this->altura = 0.0f;
	this->profundidade = 0.0f;
	this->rotacao = 0.0f;
	this->deslocamento_x = 0.0f;
	this->deslocamento_y = 0.0f;
	this->deslocamento_z = 0.0f;
}

Modelo::Modelo(float largura, float altura, float profundidade, float rotacao, float deslocamento_x, float deslocamento_y, float deslocamento_z){
	this->largura = largura;
	this->altura = altura;
	this->profundidade = profundidade;
	this->rotacao = rotacao;
	this->deslocamento_x = deslocamento_x;
	this->deslocamento_y = deslocamento_y;
	this->deslocamento_z = deslocamento_z;
}

void Modelo::set_largura(float largura){
	this->largura = largura;
}

float Modelo::get_largura(){
	return this->largura;
}

void Modelo::set_altura(float altura){
	this->altura = altura;
}

float Modelo::get_altura(){
	return this->altura;
}

void Modelo::set_profundidade(float profundidade){
	this->profundidade = profundidade;
}

float Modelo::get_profundidade(){
	return this->profundidade;
}

void Modelo::set_rotacao(float rotacao){
	this->rotacao = rotacao;
}

float Modelo::get_rotacao(){
	return this->rotacao;
}

void Modelo::set_deslocamento_x(float deslocamento_x){
	this->deslocamento_x = deslocamento_x;
}

float Modelo::get_deslocamento_x(){
	return this->deslocamento_x;
}

void Modelo::set_deslocamento_y(float deslocamento_y){
	this->deslocamento_y = deslocamento_y;
}

float Modelo::get_deslocamento_y(){
	return this->deslocamento_y;
}

void Modelo::set_deslocamento_z(float deslocamento_z){
	this->deslocamento_z = deslocamento_z;
}

float Modelo::get_deslocamento_z(){
	return this->deslocamento_z;
}
