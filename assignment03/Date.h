#include <string>

class Date
{
   private:
      unsigned day;
      unsigned month;
      std::string monthName;
      unsigned year;
      bool isLeap( unsigned ) const;
      unsigned daysPerMonth( unsigned m, unsigned y ) const;
      std::string name( unsigned m ) const;
      unsigned number( const std::string &mn ) const;

   public:
      Date();
      Date(unsigned m, unsigned d, unsigned y);
      Date(const std::string&mn, unsigned d, unsigned y);
      void printNumeric() const;
      void printAlpha() const;
};