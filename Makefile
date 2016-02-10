UNAME := $(shell uname)

BOOST_DIR=/usr/local/include  #path to boost/program_options sources
BOOST_LIB_DIR=/usr/local/lib

BOOST_FLAG=-I$(BOOST_DIR)    -m64 -fPIC -fno-strict-aliasing \
                       -fexceptions -O -DIL_STD

BOOST_CXX_LDDIRS= -L$(BOOST_LIB_DIR)
LDDIRS 	+=$(BOOST_CXX_LDDIRS)

CXXFLAGS += -Wall  $(BOOST_FLAG) -g #-DNVERBOSE

LINK     := g++
CCXX     := g++ -c #compile and assemble but do not link

first: first.cpp
	$(LINK) $(LDDIRS) first.cpp -o first -lboost_program_options -pthread -lm $(CXXFLAGS)
