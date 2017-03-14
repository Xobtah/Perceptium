//
// Created by xobtah on 03/03/17.
//

#include <algorithm>

#include "NeuralNetwork.hpp"

namespace Perceptium
{
    /*
     *  Ctor & Dtor
     */

    NeuralNetwork::NeuralNetwork() {}

    NeuralNetwork::NeuralNetwork(unsigned int input, unsigned int output)
    {
        _network.push_back(std::vector<Perceptron>(input, Perceptron(0)));
        _network.push_back(std::vector<Perceptron>(input + 1, Perceptron(input)));
        _network.push_back(std::vector<Perceptron>(output, Perceptron(input + 1)));
    }

    NeuralNetwork::~NeuralNetwork() {}

    /*
     *  Public member functions
     */

    /*NeuralNetwork   &NeuralNetwork::NewLayer()
    {
        _network.push_back(std::vector<Perceptron>());
        return (*this);
    }

    NeuralNetwork   &NeuralNetwork::NewPerceptron()
    {
        Perceptron  p;

        if (!_network.size())
            this->NewLayer();
        if (_network.size() != 1)
            p.NewLink(_network[_network.size() - 2].size());
        _network[_network.size() - 1].push_back(p);
        return (*this);
    }*/

    std::vector<float>  NeuralNetwork::Run(std::vector<float> inputs) { return (this->Run(inputs, 0)); }

    /*
     *  Private member functions
     */

    std::vector<float>  NeuralNetwork::Run(std::vector<float> inputs, unsigned int layer)
    {
        std::vector<float>  currentData/*(_network[layer].size())*/;

        if (layer)
        {
            std::for_each(_network[layer].begin(), _network[layer].end(), [&](Perceptron &item)
            { currentData.push_back(item.Run(inputs)); });
        }
        else
            currentData = inputs;
        if (layer != _network.size() - 1)
            return (this->Run(currentData, layer + 1));
        return (currentData);
    }
}