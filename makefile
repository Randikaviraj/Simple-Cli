
CXXFLAGS = -std=c++17

cli:main Catlog Course View Controller
	$(CXX) $(CXXFLAGS) main.o Catalog.o Course.o View.o Controller.o
	./a.out

main:main.cpp Controller.h Catalog.h Course.h View.h
	$(CXX) $(CXXFLAGS) -c main.cpp 

Controller:Controller.cpp Controller.h View.h Catalog.h Course.h
	$(CXX) $(CXXFLAGS) -c Controller.cpp

View: View.cpp View.h Catalog.h Course.h
	$(CXX) $(CXXFLAGS) -c View.cpp

Catlog:Catalog.cpp Course.h Catalog.h
	$(CXX) $(CXXFLAGS) -c Catalog.cpp

Course:Course.cpp Course.h
	$(CXX) $(CXXFLAGS) -c Course.cpp



clean:
	rm -f *.o a.out