#ifndef DATE_H
#define DATE_H

#include <string>

class Date
{
    private:       
        int month;   
        int day;           
        int year;       

    public:       

        class InvalidDay
        {
            private:
                int invalidDay;

            public:
                InvalidDay(int dayVal)
                { invalidDay = dayVal; }

                int getInvalidDay() const
                { return invalidDay; }
        };

        class InvalidMonth
        {
            private:
                int invalidMonth;

            public:
                InvalidMonth(int monthVal)
                { invalidMonth = monthVal; }

                int getInvalidMonth() const
                { return invalidMonth; }
        };
        
        class InvalidYear
        {
            private:
                int invalidYear;

            public:
                InvalidYear(int yearVal)
                { invalidYear = yearVal; }

                int getInvalidYear() const
                { return invalidYear; }
        };
       
        Date();
        Date(int aDay, int aMonth, int aYear);
        /* const Date Operator++(const Date& otherDate);*/
        Date operator++(int aDay);
        Date operator--(int aDay);
        
        // Mutator functions
        bool isLeapYear();
        void setMonth(int aMonth);
        void setDay(int aDay);
        void setYear(int aYear);
        void listAllDates();

        // Accessor functions
        void getToString1() const;
        void getToString2() const;
        void getToString3() const;
};

#endif