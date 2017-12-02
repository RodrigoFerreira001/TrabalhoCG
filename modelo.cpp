#include "modelo.hpp"

Moledo::Moledo(){
	this->largura = 0.0f;
	this->altura = 0.0f;
	this->profundidade = 0.0f;
	this->rotacao = 0.0f;
	this->deslocamento_x = 0.0f;
	this->deslocamento_y = 0.0f;
}
Moledo::Modelo(float largura, float altura, float profundidade, float rotacao, float deslocamento_x, float deslocamento_y){
	this->largura = largura;
	this->altura = altura;
	this->profundidade = profundidade;
	this->rotacao = rotacao;
	this->deslocamento_x = deslocamento_x;
	this->deslocamento_y = deslocamento_y;
}

void Moledo::set_largura(float largura){
	this->largura = largura;
}

float Moledo::get_largura(){
	return this->largura;
}

void Moledo::set_altura(float altura){
	this->altura = altura;
}

float Moledo::get_altura(){
	return this->altura;
}

void Moledo::set_profundidade(float profundidade){
	this->profundidade = profundidade;
}

float Moledo::get_profundidade(){
	return this->profundidade;
}

void Moledo::set_rotacao(float rotacao){
	this->rotacao = rotacao;
}

float Moledo::get_rotacao(){
	return this->rotacao;
}

void Moledo::set_deslocamento_x(float deslocamento_x){
	this->deslocamento_x = deslocamento_x;
}

float Moledo::get_deslocamento_x(){
	return this->deslocamento_x;
}

void Moledo::set_deslocamento_y(float deslocamento_y){
	this->deslocamento_y = deslocamento_y;
}
float Moledo::get_deslocamento_y(){
	return this->deslocamento_y;
}
