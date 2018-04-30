// Copyright 2018 Okunev Boris

#ifndef MODULES_INTEGER_NUMERICAL_INTERVAL_INCLUDE_INTEGER_NUMERICAL_INTERVAL_H_
#define MODULES_INTEGER_NUMERICAL_INTERVAL_INCLUDE_INTEGER_NUMERICAL_INTERVAL_H_

#include <string>
#include <vector>

using std::vector;

class IntegerNumericalInterval {
 public:
    IntegerNumericalInterval();
    IntegerNumericalInterval(const int leftBorder,const int rightBorder,
        const bool isIncludeLeft,const bool isIncludeRight);
    IntegerNumericalInterval(const std::string& interval);
    IntegerNumericalInterval(const IntegerNumericalInterval& ni);


    bool isContainPoints(const vector<int>& points);
    bool isHaveOverlapsRange(const IntegerNumericalInterval& ni);
    bool isContainsRange(const IntegerNumericalInterval& ni);

    vector<int> getAllPoints() const;
    vector<int> getEndPoints() const;

    bool operator == (const IntegerNumericalInterval& ni) const;
    bool operator != (const IntegerNumericalInterval& ni) const;
    operator std::string();

 private:
    bool isInitializationCorrect(const int leftBorder, const int rightBorder,
        const bool isIncludeLeft, const bool isIncludeRight);

 private:
    int leftBorder_;
    int rightBorder_;
    bool isIncludeLeft_;
    bool isIncludeRight_;
};

#endif  // MODULES_INTEGER_NUMERICAL_INTERVAL_INCLUDE_INTEGER_NUMERICAL_INTERVAL_H_
