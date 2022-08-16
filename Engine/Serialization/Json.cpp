#include "Json.h"
#include "rapidjson/istreamwrapper.h"


namespace c14::json
{
	bool Load(const std::string filename, rapidjson::Document& document)
	{
		// !! create a std::ifstream object called stream 
		 // !! check if it is open, if not use LOG to print error and return false 
		// !! https://riptutorial.com/cplusplus/example/1625/opening-a-file 

		rapidjson::IStreamWrapper istream(stream);
		document.ParseStream(istream);
		if (document.IsObject() == false)
		{
			LOG("json file cannot be read %s.", filename.c_str());
			return false;
		}

		return true;
	}

	bool Get(const rapidjson::Value& value, const std::string& name, int& data)
	{
		return false;
	}

	bool Get(const rapidjson::Value& value, const std::string& name, float& data)
	{
		return false;
	}

	bool Get(const rapidjson::Value& value, const std::string& name, bool& data)
	{
		return false;
	}

	bool Get(const rapidjson::Value& value, const std::string& name, std::string& data)
	{
		return false;
	}

	bool Get(const rapidjson::Value& value, const std::string& name, Vector2& data)
	{
		return false;
	}

	bool Get(const rapidjson::Value& value, const std::string& name, Color& data)
	{
		return false;
	}

}
