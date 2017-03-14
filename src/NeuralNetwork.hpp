//
// Created by xobtah on 03/03/17.
//

#ifndef PERCEPTIUM_NEURALNETWORK_HPP
#define PERCEPTIUM_NEURALNETWORK_HPP

#include <vector>
#include <utility>

#include "Perceptron.hpp"

namespace Perceptium
{
    class NeuralNetworkException : public std::exception
    {
    public:
        NeuralNetworkException(std::string what) throw() : _what(what) {}
        ~NeuralNetworkException() {}

        virtual const char  *what() const throw() { return _what.c_str(); }

    private:
        std::string _what;
    };

    class   NeuralNetwork
    {
    public:
        NeuralNetwork();
        NeuralNetwork(unsigned int, unsigned int);
        ~NeuralNetwork();

        /*NeuralNetwork   &NewLayer();
        NeuralNetwork   &NewPerceptron();*/

        std::vector<float>  Run(std::vector<float>);

    private:
        std::vector<std::vector<Perceptron>>    _network;

        std::vector<float>  Run(std::vector<float>, unsigned int layer);
    };
}

#endif //PERCEPTIUM_NEURALNETWORK_HPP
