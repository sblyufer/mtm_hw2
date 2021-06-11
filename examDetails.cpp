//
// Created by Sofia Blyufer on 10/06/2021.
//
#include <iostream>
#include "examDetails.h"
#include <math.h>

#define DAYS_IN_MONTH 30
namespace mtm
{
    enum ErrorCode {InvalidArgsException, InvalidDateException, InvalidTimeException} MtmErrorCode;
    class ExamDetails
    {
    private:
        int course_number, exam_month, exam_day, exam_duration;
        double exam_hour;
        std::string zoom_link;
    public:
        //c'tors
        ExamDetails(int course_number, int exam_month, int exam_day,
                    double exam_hour, int exam_duration, std::string zoom_link); //change to doubles
       // ~ExamDetails();
        static ExamDetails makeMatamExam()
        {
            ExamDetails exam_matam(int 234124, int 7, int 28,
                    double 13.0, int 3, "https://tinyurl.com/59hzps6m");
            return exam_matam;
        }
        ExamDetails(const ExamDetails& exam_details);
        //operators
        ExamDetails& operator = (const ExamDetails& exam_details) = default;
//        {
//            course_number = exam_details.course_number;
//            exam_month = exam_details.exam_month;
//            exam_day = exam_details.exam_day;
//            exam_hour = exam_details.exam_hour;
//            exam_duration = exam_details.exam_duration;
//            zoom_link = exam_details.zoom_link;
//            return *this;
//        }
        int operator - (const ExamDetails& exam_details) const
        {
            int diff = (exam_month - exam_details.exam_month)*(DAYS_IN_MONTH) +
                    (exam_day - exam_details.exam_day);
            return diff;
        }
        bool operator < (const ExamDetails& exam_details) const
        {
            int diff = *this - exam_details;
            if (diff < 0)
            {
                return true;
            }
            if (diff == 0)
            {
                if (exam_hour < exam_details.exam_hour)
                {
                    return true;
                }
            }
            return false;
        }
        //methods
        std::string getLink() const;
        void setLink(std::string new_link);
        //friends
        friend std::ostream& operator<<(std::ostream&, const String&);
    };

    ExamDetails::ExamDetails(int course_number, double exam_month, double exam_day,
                double exam_hour, double exam_duration, std::string zoom_link = "")
    {
        if(exam_month >= 12.000001 || exam_month < 0.999999 || exam_day < 0.999999 ||
                exam_day > 30)
        {
            throw InvalidDateException();
        }

        int int_part = (int) exam_hour;
        //double exam_hour, fract_part, int_part;
        //fract_part = modf (exam_hour , &int_part);
        //if((exam_hour > 22.499999 || exam_hour < 0.000001
          //  || (fract_part < 0.000001 && fract_part > -0.000001
           // && fract_part < 0.5000001 && exam_hour >)
          //  || exam_duration < 0))
        {
            throw InvalidTimeException();
        }

    }

    ExamDetails::~ExamDetails()
    {


    ExamDetails::ExamDetails(const ExamDetails& exam_details) = default;
//    {
//        ExamDetails new_exam = new ExamDetails;
//        new_exam.course_number = course_number;
//        new_exam.exam_month = exam_month;
//        new_exam.exam_day = exam_day;
//        new_exam.exam_hour = exam_hour;
//        new_exam.exam_duration = exam_duration;
//        new_exam.zoom_link = zoom_link;
//
//    }

    std::string ExamDetails::getLink() const
    {
        return zoom_link;
    }

    void ExamDetails::setLink(std::string new_link)
    {
        zoom_link = new_link;
    }
}

