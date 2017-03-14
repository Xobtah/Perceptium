//
// Created by xobtah on 06/03/17.
//
#include <iostream>

#include <cmath>
#include <algorithm>

#include "Perceptron.hpp"

namespace Perceptium
{
    /*
     *  Ctor & Dtor
     */

    Perceptron::Perceptron(unsigned int linkNb) : _delta(this->Rand())
    {
        std::srand(std::time(0) * std::time(0));
        while (linkNb--)
            this->NewLink(this->Rand());
    }

    Perceptron::~Perceptron() {}

    /*
     *  Public member functions
     */

    Perceptron  &Perceptron::NewLink(float val)
    {
        _weights.push_back(val);
        return (*this);
    }

    Perceptron  &Perceptron::NewLink(std::vector<float> weights)
    {
        std::for_each(weights.begin(), weights.end(), [&](float val) { _weights.push_back(val); });
        return (*this);
    }

    float   Perceptron::Run(std::vector<float> inputs) { return (this->Activation(this->WeightedSum(inputs) - _delta)); }

    Perceptron  Perceptron::SetDna(std::vector<float> dna)
    {
        _weights.clear();
        std::for_each(dna.begin(), dna.end() - 1, [&](float val) { _weights.push_back(val); });
        _delta = dna[dna.size() - 1];
        return (*this);
    }

    std::vector<float>  Perceptron::GetDna() const
    {
        std::vector<float>  dna(_weights);

        dna.push_back(_delta);
        return (dna);
    }

    Perceptron  Perceptron::SetDelta(float val)
    {
        _delta = val;
        return (*this);
    }

    float   Perceptron::GetDelta() const { return (_delta); }

    float   Perceptron::Rand()
    {
        float   nb = std::rand();

        while (nb > 1)
            nb /= 10;
        return (nb);
    }

    /*
     *  Private member functions
     */

    float   Perceptron::WeightedSum(std::vector<float> inputs)
    {
        float   nb = 0;
        unsigned int    i = 0;

        if (inputs.size() != _weights.size())
            throw PerceptronException("Not same number of inputs & weights");
        while (i < inputs.size())
        {
            nb += inputs[i] * _weights[i];
            i++;
        }
        return (nb);
    }

    float   Perceptron::Activation(float x) { return (1 / (1 + exp(-x))); }
}