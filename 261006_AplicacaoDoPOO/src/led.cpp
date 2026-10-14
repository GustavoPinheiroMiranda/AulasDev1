#include "led.h"

Led::Led(uint8_t pino)
{
    _pinoLed = pino;
}

void Led::iniciar()
{
    pinMode(_pinoLed, OUTPUT);
    digitalWrite(_pinoLed, LOW);
}

void Led::atualizar()
{
    const uint32_t tempoDecorrido =
        millis() - _tempoAnteriorAcionamento_ms;

    if (tempoDecorrido >= _intervaloPiscar_ms)
    {
        _tempoAnteriorAcionamento_ms = millis();
        alternar();
    }

    digitalWrite(_pinoLed, _estadoLed);
}

void Led::ligar()
{
    _estadoLed = HIGH;
}

void Led::desligar()
{
    _estadoLed = LOW;
}

void Led::ativarPiscar(uint32_t tempo_ms)
{
    _intervaloPiscar_ms = tempo_ms;
}

void Led::desativarPiscar()
{
    _estadoLed = LOW;
}

void Led::alternar()
{
    _estadoLed = !_estadoLed;
}

void Led::estadoLento()
{
    _intervaloPiscar_ms = 1000;
}

void Led::estadoRapido()
{
    _intervaloPiscar_ms = 200;
}