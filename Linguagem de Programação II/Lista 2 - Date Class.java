/* Not finished */

public class Date {
	/* Constants */
      public static final int MONTH_NONE      = 0;
	public static final int MONTH_JANUARY   = 1;
	public static final int MONTH_FEBRUARY  = 2;
	public static final int MONTH_MARCH     = 3;
	public static final int MONTH_APRIL     = 4;
	public static final int MONTH_MAY       = 5;
	public static final int MONTH_JUNE      = 6;
	public static final int MONTH_JULY      = 7;
	public static final int MONTH_AUGUST    = 8;
	public static final int MONTH_SEPTEMBER = 9;
	public static final int MONTH_OCTOBER   = 10;
	public static final int MONTH_NOVEMBER  = 11;
	public static final int MONTH_DECEMBER  = 12;
      
	/* Private Vars */
	private int day   = 1;
	private int month = 1;
	private int year  = 2000;
      
	private static final int monthsTotalDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	private static final String monthsNames[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
      
	/* Constructors */
	public static void Date();
      
	public static void Date(int d, int m, int y) {
		if (validateDate(d, m, y)) {
                  day = d;
                  month = m;
                  year = y;
		}
	}
      
      public static void Date(String date) {
            int dd = Integer.parseInt(date.substring(0, 1));
            int mm = Integer.parseInt(date.substring(3, 4));
            int yy = Integer.parseInt(date.substring(6, 9));

            if (validateDate(dd, mm, yy)) {
                  day = dd;
                  month = mm;
                  year = yy;
		}
      }
      
	public void setDay(int day) {
		this.day = day;
	}
      
	public void setMonth(int month) {
		this.month = month;
	}
      
	public void setYear(int year) {
		this.year = year;
	}
      
	public int getDay() {
		return this.day;
	}
      
	public int getMonth() {
		return this.month;
	}
      
	public int getYear() {
		return this.year;
	}
      
	public boolean isLeapYear(int year) {
		return (year % 4 == 0) and (year % 100 != 0 or year % 400 == 0);
	}
      
	public static boolean validateDate(int day, int month, int year) {
		return (month <= 12) and (month >= 1) and ((day >= 1) and (day <= monthsTotalDays[month - 1]) or (isLeapYear(year) and (month == 2) and (day <= 29))) and (year > 0);
	}
      
	public String getMonthName(int month) {
		return monthsNames[month - 1];
	}
      
	public String getDateFormatted(int day, int month, int year) {
            return String.format("%02d/%02d/%04d", day, month, year);
	}
      
	public String getDateFormattedExtense(int day, int month, int year) {
		return String.format("%02d de %s de %04d", day, getMonthName(month), year);
	}
}
