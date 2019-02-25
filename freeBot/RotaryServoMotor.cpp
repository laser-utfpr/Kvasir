#include "RotaryServoMotor.hpp"

RotaryServoMotor::RotaryServoMotor(int _pwm_pin, float _max_speed, int _adjust_speed)
{
    pwm_pin = _pwm_pin;
    max_speed = _max_speed;
    adjust_speed = _adjust_speed;
    servo = new VarSpeedServo();
    servo->attach(pwm_pin);
    servo->write(adjust_speed);//--Manda iniciar com o motor parado
}

void RotaryServoMotor::setSpeed(float speed)
{
    float ang;
    ang = (speed*90)/max_speed; //regra de tres para transformar a velocidade recebida num angulo
    if(speed==0)
    {
        servo->detach(); //o servo eh desligado para melhor controle da velocidade de parada, ja que com a temperatura a mesma vai mudando, e tambem para economizar energia
    }
    else
    {
        servo->attach(pwm_pin);
        servo->write(ang + adjust_speed);//--sentido horário se angulo é positivo ou ~
        //Serial.println("estou andando");
    }
}
