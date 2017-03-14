//
// Created by xobtah on 06/03/17.
//

#ifndef PERCEPTIUM_PERCEPTRON_HPP
#define PERCEPTIUM_PERCEPTRON_HPP

#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>

namespace Perceptium
{
    class PerceptronException : public std::exception
    {
    public:
        PerceptronException(std::string what) throw() : _what(what) {}
        ~PerceptronException() {}

        virtual const char  *what() const throw() { return _what.c_str(); }

    private:
        std::string _what;
    };

    class Perceptron
    {
    public:
        Perceptron(unsigned int);
        ~Perceptron();

        Perceptron  &NewLink(float);
        Perceptron  &NewLink(std::vector<float>);

        Perceptron  SetDna(std::vector<float>);
        std::vector<float>  GetDna() const;

        Perceptron  SetDelta(float);
        float   GetDelta() const;

        float   Run(std::vector<float>);

        static float    Rand();

    private:
        float   _delta;
        std::vector<float>  _weights;

        float   WeightedSum(std::vector<float>);
        float   Activation(float);
    };
}

#endif //PERCEPTIUM_PERCEPTRON_HPP
