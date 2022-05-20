#include <iostream>
#include <vector>
#include <map>
#include "string"
#include <unordered_map>


struct SchoolRecord
{
	std::string Name;
	uint32_t TotalEnrollment;
	double Latitude, Longitude;

	// Important for both sorting and hashing
	bool operator<(const SchoolRecord& other) const
	{
		return TotalEnrollment < other.TotalEnrollment;
	}
};

namespace std {
	
	template<>
	struct hash<SchoolRecord> 
	{
		size_t operator()(const SchoolRecord& key) 
		{
			return hash<std::string>()(key.Name);
		}
	};
}

void RunMapFile()
{
	// using vector
	/*std::vector<SchoolRecord> schools;
	schools.emplace_back("Law", 1003, 3.3, 2.1);
	schools.emplace_back("Platt Tech", 904, 3.3, 2.1);
	schools.emplace_back("Foran", 353, 3.3, 2.1);
	schools.emplace_back("Nathans Rigg", 1532, 3.2, 2.1);*/

	// Would have to do binary search(if items are sorted) or binary search to find a item; takes time :(
	/*for (const auto& school : schools)
	{
		if (school.Name == "Foran")
		{
			uint32_t enrollment = school.TotalEnrollment;
			break;
		}
	}*/

	// DOES NOT WORK FIX
	/*std::unordered_map<SchoolRecord, uint32_t> foundedMap;

	foundedMap[SchoolRecord{ "Law", 1003, 3.3, 2.1 }] = 1967;*/
	// DOES NOT WORK FIX

	// Would still work even though the TotalEnrollment of object is different since the schools Name is the
	// key since it was the variable hashed
	//std::cout << foundedMap[SchoolRecord{ "Law", 33, 3.3, 2.1 }] << std::endl;;

	// use map for ordered map 
	std::unordered_map<std::string, SchoolRecord> schoolMap;
	schoolMap["Law"] = SchoolRecord{ "Law", 1003, 3.3, 2.1 };
	schoolMap["Platt tech"] = SchoolRecord{ "Platt Tech", 904, 3.3, 2.1 };
	schoolMap["Foran"] = SchoolRecord{ "Foran", 353, 3.3, 2.1 };
	schoolMap["Nathans Rigg"] = SchoolRecord{ "Nathans Rigg", 1532, 3.2, 2.1 };

	std::map<SchoolRecord, uint32_t> schoolFounded;
	schoolFounded[SchoolRecord{ "Law", 1003, 3.3, 2.1 }];
	schoolFounded[SchoolRecord{ "Bronx High", 10033, 3.3, 2.1 }];

	// Get enrollment of platt tech
	SchoolRecord Platt = schoolMap["Platt tech"];

	const auto& schools = schoolMap;
	if (schoolMap.find("Platt tech") != schools.end())
	{
		const SchoolRecord& plattData = schools.at("Platt tech");
	}


	// Old shitty way :( of doing map iteration
	//for (auto& Kv : schoolMap)
	//{
	//	const std::string& name = Kv.first;
	//	SchoolRecord& school = Kv.second;
	//}

	schoolMap.erase("Foran");
	// Uses structure bindings. learn more
	for (auto& [name, school] : schoolMap)
	{
		//std::cout << name << ":\n" << "Total Enrollment: " << school.TotalEnrollment << std::endl;
		schoolFounded[school];
	}

	for (auto& [school, founded] : schoolFounded)
	{
		std::cout << school.Name << ":\n" << "Total Enrollment: " << school.TotalEnrollment << std::endl;
	}


	// This would "work" because, the [] is not const and using it would insert data(if it does not exist)
	// and retrieve data
	SchoolRecord& StratfordHighData = schoolMap["Stratford High"];
	// Useful cause this:
	StratfordHighData.Name = "Stratford High";
	StratfordHighData.TotalEnrollment = 10000;
	StratfordHighData.Latitude = 323.3;
	StratfordHighData.Longitude = 321.2;

}