#include <iostream>
#include <vector>
#include <new>
#include <cstring>
#include <cstdlib>

#include "cgicc/CgiDefs.h"
#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "cgicc/HTMLClasses.h"

using namespace std;
using namespace cgicc;


Cgicc formData;
class DB{
private:
	form_iterator name = formData.getElement("name"),
								userAddress = formData.getElement("address"),
								city = formData.getElement("city"),
								district = formData.getElement("district"),
								province = formData.getElement("province"),
								cnic = formData.getElement("cnic"),
								phone = formData.getElement("phone"),
								gender = formData.getElement("gender"),
								interTotalMarks = formData.getElement("intertotalmarks"),
								interMarks = formData.getElement("intermarks"),
								matricTotalMarks = formData.getElement("matrictotalmarks"),
								matricMarks = formData.getElement("matricmarks"),
								degree = formData.getElement("degree");
	string dbfname,
				 dblname,
				 dbcity,
				 dbgender,
				 dbdistrict,
				 dbprovince,
				 dbdegree,
				 dbcnic,
				 dbphone;
	
	float dbitm,
			dbim,
			dbmtm,
			dbmm;

public:
	void show(){
		
		ofstream dbTestOut("testdb.txt");		
	
		dbTestOut << **name << "\t" << 
						 **city << "\t" <<
						 **district << "\t" <<
						 **province << "\t" <<
						 **cnic << "\t" <<
						 **phone << "\t" <<
						 **gender << "\t" <<
						 **interTotalMarks << "\t" <<
						 **interMarks << "\t" <<
						 **matricTotalMarks << "\t" <<
						 **matricMarks << "\t" <<
						 **degree << endl;
		dbTestOut.close();

		ifstream dbTestIn("testdb.txt");		

		dbTestIn >> dbfname >> dblname >> dbcity >> dbdistrict >> dbprovince >> dbcnic >> dbphone >> dbgender >> dbitm >> dbim >> dbmtm >> dbmm >> dbdegree;
		

		if(dbcnic.length() == 13 && dbphone.length() == 11 && dbitm == 1100 && dbim < dbitm && (dbmtm == 1100 || dbmtm == 1050) && dbmm < dbmtm){
			ofstream dbOut("db.txt", ios::app);
			
			float interPercentage = ((dbim/dbitm)*100),
					matricPercentage = ((dbmm/dbmtm)*100),
					aggregate = ((interPercentage+matricPercentage)/2);


			dbOut << **name << "\t" <<
							 **city << "\t" <<
							 **district << "\t" <<
							 **province << "\t" <<
							 **cnic << "\t" <<
							 **phone << "\t" <<
							 **gender << "\t" <<
							 **interTotalMarks << "\t" <<
							 **interMarks << "\t" <<
							 interPercentage << "\t" <<
							 **matricTotalMarks << "\t" <<
							 **matricMarks << "\t" <<
							 matricPercentage << "\t" <<
							 aggregate << "\t" <<
							 **degree;
			cout << "<html><head><meta http-equiv=\"refresh\" content=\"5; url=http://localhost/pugc/index.php\"</head><body>Registration Complete... You will be redirected shortly...</body></html>" << endl;


		} else {
			cout << "Failed" << endl;
			cout << dbfname << dblname << dbcity << dbdistrict << dbprovince << dbcnic << dbphone << dbgender << dbitm << dbim << dbmtm << dbmm << dbdegree << endl;
		}

	}

};
int main(){

	DB db;

	cout << "Content-type:text/html\n\r\n\r" << endl;

	db.show();

return 0;
}
