#pragma once

template<class T>
class Generator {
public:
    virtual ~Generator() = default;

    virtual T generate() = 0;
};
