#Create cpp libraries both static and dynamic
export SHELL  = /bin/csh
STATICTARGET     = static-libcard
DYNTARGET        = dynamic-libcard

CPPCOMPILER      = g++

CPPEleven        = -std=c++11
CPPTwenty        = -std=c++20


#no need for assemblor step
#for production code
#-x assemblor or -x assemblor-with-cpp to be skipped for final code
#TOAN -Wignore-qualifiers
STRICTOPTIONS    = -Wall -Wreorder -Werror -fstrict-enums -fno-cx-fortran-rules
PLANGUAGES       = -x c-header    -x c++-header \
                   -x c           -x c++


STATICLIBOPTIONS = -fPIC -static
DYNLIBOPTIONS    = -fPIC -fpic -shared


INCLUDES         = Includes/card.hpp Includes/cardcst.hpp
SOURCES          = Sources/card.cpp


$(DYNTARGET) :
	$(CPPCOMPILER) $(CPPEleven) $(STRICTOPTIONS) \
        $(PLANGUAGES)                                \
        -IIncludes $(DYNLIBOPTIONS)                  \
        $(SOURCES) -o libcard.so


$(STATICTARGET) :
	$(CPPCOMPILER) $(CPPEleven) $(STRICTOPTIONS) $(PLANGUAGES) \
        -S $(SOURCES) $(STATICLIBOPTIONS) -IIncludes -o libcard.a


$(TARGET) :
	if ($(TARGET) == "dynamic-libcard") then
	  ./$(DYNTARGET)
	else if ($(TARGET) == "static-libcard") then
	  ./$(STATICTARGET)
	endif


Moov :
	mv libcard.so /usr/local/lib64; mv libcard.a /usr/local/lib64
