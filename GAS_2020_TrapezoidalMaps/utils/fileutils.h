#ifndef FILEUTILS_H
#define FILEUTILS_H

#include <vector>
#include <cg3/geometry/point2.h>
#include <cg3/geometry/segment2.h>

namespace FileUtils {

std::vector<cg3::Segment2d> getSegmentsFromFile(const std::string& filename);

std::vector<cg3::Segment2d> saveSegmentsInFile(const std::string& filename, const std::vector<cg3::Segment2d>& segments);

}

#endif // FILEUTILS_H
