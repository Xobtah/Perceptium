//
// Created by xobtah on 03/03/17.
//

#include <iostream>
#include <vector>

#include "../src/NeuralNetwork.hpp"

int main()
{
    std::vector<float>  inputs(2, 0.5);
    Perceptium::Perceptron  perc(2);
    Perceptium::NeuralNetwork   ann(2, 1);

    std::cout << "Perceptron: " << perc.Run(inputs) << std::endl;
    std::cout << "Network: " << ann.Run(inputs)[0] << std::endl;
    return (0);
}