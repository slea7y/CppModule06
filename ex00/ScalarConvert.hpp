#include <iostream>

class ScalarConverte {
 	private:
		ScalarConverte();
	public:
		virtual ~ScalarConverte();
		static void convert(std::string& string);
};