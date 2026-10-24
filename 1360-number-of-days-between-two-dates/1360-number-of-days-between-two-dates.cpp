class Solution {
public:
    bool isLeap(int year) {
            // A year is a leap year if it is divisible by 4, but not by 100, unless it is also divisible by 400.
            return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        }
    int dates(int year,int month,int day){
        vector<int>maxDays = {31,28,31,30,31,30,31,31,30,31,30,31};
        int date =0;
        //YEAR CALCULATION
        int i = 1971;
        while(i<year){
            date += isLeap(i)?366:365;
            i++;
        }
        //CURRENT YEAR IS LEAP YEAR OR NOT CHECK
        if(isLeap(year)){
            maxDays[1] = 29;
        }
        //CURRENT YEAR TILL THE MONTH DAYS CALCULATION
        for(int j=0;j<month-1;j++){
            date+=maxDays[j];
        }
        //CURRENT YEAR TILL MONTH TILL THE PRESENT DAY 
        date +=day;
        return date;
    }
    int daysBetweenDates(string date1, string date2) {
        stringstream ss1(date1);
        stringstream ss2(date2);
        long long startDate = 0;
        long long endDate =0;
        int startYear,startMonth,startDay;
        int endYear,endMonth,endDay;
        char dash;
        ss1>>startYear>>dash>>startMonth>>dash>>startDay;
        ss2>>endYear>>dash>>endMonth>>dash>>endDay;
        startDate = dates(startYear,startMonth,startDay);
        endDate = dates(endYear,endMonth,endDay);
        return abs(startDate-endDate);


    }
};