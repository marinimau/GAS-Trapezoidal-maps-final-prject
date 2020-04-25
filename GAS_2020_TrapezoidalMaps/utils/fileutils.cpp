#include "fileutils.h"

#include <fstream>
#include <random>
#include <iomanip>

#include "assert.h"

#include "data_structures/trapezoidalmap_dataset.h"

namespace FileUtils {

std::vector<cg3::Segment2d> getSegmentsFromFile(const std::string& filename) {
    std::vector<cg3::Segment2d> segments;
	
	std::ifstream infile;
    infile.open(filename);

    int n;
    infile >> n;

    for (int i = 0; i < n; i++) {
        double x = 0.0;
        double y = 0.0;
		
        infile >> x >> y;
        cg3::Point2d p1(x,y);
		
        infile >> x >> y;
        cg3::Point2d p2(x,y);
		
        segments.push_back(cg3::Segment2d(p1, p2));
    }
	
    return segments;
}

std::vector<cg3::Segment2d> saveSegmentsInFile(const std::string& filename, const std::vector<cg3::Segment2d>& segments) {
    std::ofstream outfile;
    outfile.open(filename);

    outfile << segments.size() << std::endl;

    for (const cg3::Segment2d& segment : segments) {
        const cg3::Point2d& p1 = segment.p1();
        const cg3::Point2d& p2 = segment.p2();

        outfile << std::fixed;
        outfile << std::setprecision(4) << p1.x() << " " << std::setprecision(4) << p1.y() << " ";
        outfile << std::setprecision(4) << p2.x() << " " << std::setprecision(4) << p2.y();
        outfile << std::endl;
    }

    outfile.close();

    return segments;
}


}
