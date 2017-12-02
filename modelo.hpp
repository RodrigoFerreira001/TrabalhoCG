#pragma once

class Modelo{
private:
  float largura;
  float altura;
  float profundidade;
  float rotacao;
  float deslocamento_x;
  float deslocamento_y;
  float deslocamento_z;

public:
  Modelo();
  Modelo(float largura);
  Modelo(float largura, float altura, float profundidade, float rotacao, float deslocamento_x, float deslocamento_y, float deslocamento_z);

  void set_largura(float largura);
  float get_largura();

  void set_altura(float altura);
  float get_altura();

  void set_profundidade(float profundidade);
  float get_profundidade();

  void set_rotacao(float rotacao);
  float get_rotacao();

  void set_deslocamento_x(float deslocamento_x);
  float get_deslocamento_x();

  void set_deslocamento_y(float deslocamento_y);
  float get_deslocamento_y();

  void set_deslocamento_z(float deslocamento_z);
  float get_deslocamento_z();
};
