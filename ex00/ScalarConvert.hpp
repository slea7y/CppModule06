#include <iostream>

class ScalarConverte {
 	public:	
		virtual ~ScalarConverte() = delete;
		static void convert(const std::string& string);
	private:
		ScalarConverte() = delete;
		ScalarConverte(const ScalarConverte& other)  = delete;
		ScalarConverte operator=(const ScalarConverte& other)  = delete;

		enum TYPE { CHAR, INT, FLOAT, DOUBLE, INVALID };
		static void detectType(TYPE *type, const std::string& string);
		static void handleChar(const std::string& string);
		static void handleInt(const std::string& string);
		static void handleFloat(const std::string& string);
		static void handleDouble(const std::string& string);
};