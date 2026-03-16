#include <iostream>

class ScalarConverte {
 	public:	
		virtual ~ScalarConverte();
		static void convert(std::string& string);
	private:
		ScalarConverte();
		ScalarConverte(const ScalarConverte& other);
		ScalarConverte operator=(const ScalarConverte& other);
};