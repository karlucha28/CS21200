#include "stats.h"
// to handle errors for mean, minimum and maximum
#include <cassert> 



namespace main_savitch_2C
{
    // constructor
    statistician::statistician(){
        count = 0;
        total = 0;
        tinyest = 0;
        largest = 0;
    }

    // member functions
    void statistician::next(double r){
    	if(count == 0){
            tinyest = r;
            largest = r;
        } else {
            if(r < tinyest){
                tinyest = r;
            } else if( r > largest){
                largest = r;
            }
        }
        total = total + r;
        count++;
	}

    void statistician::reset(){
        count = 0;
        total = 0;
        tinyest = 0;
        largest = 0;
    }

    // const functions
    int statistician::length() const {
        return count;
    }

    double statistician::sum() const {
        return total;
    }

    double statistician::mean() const {
        assert(count > 0);
        return total/count;
       
    }

    double statistician::minimum() const {
        assert(count > 0);
        return tinyest;
       
    }

    double statistician::maximum() const {
        assert(count > 0);
        return largest;
    
    }

    // friend functions
    statistician operator +(const statistician& s1, const statistician& s2){
        statistician sum;
        if(s1.count == 0) return s2;
        if(s2.count == 0) return s1;
        sum.total = s1.total + s2.total;
        sum.count = s1.count + s2.count;
        sum.tinyest = (s1.tinyest < s2.tinyest) ? s1.tinyest : s2.tinyest;
        sum.largest = (s1.largest > s2.largest) ? s1.largest : s2.largest;
        return sum;
    }

    statistician operator *(double scale, const statistician& s){
        statistician mult;
        if(s.count == 0) return s;
        mult.total = s.total*scale;
        mult.count = s.count;
        mult.tinyest = (scale > 0) ? s.tinyest*scale : s.largest*scale ;
        mult.largest = (scale > 0) ? s.largest*scale  : s.tinyest*scale ;
        return mult;
    }
    // outsider function (non-member)
    bool operator ==(const statistician& s1, const statistician& s2){
        //using const fun to get the counts
        if(s1.length() == 0 && s2.length() == 0) return true;
        if(
            s1.length() == s2.length() 
            && s1.mean() == s2.mean() 
            && s1.minimum() == s2.minimum() 
            && s1.maximum() == s2.maximum()
        ){
            return true;
        } else {
            return false;
        }
    }

}
