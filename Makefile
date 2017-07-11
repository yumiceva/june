CC = g++
CFLAGS = `root-config --auxcflags` -fPIC
INC = -I`root-config --incdir`
LDFLAGS = `root-config --libs`
# setup boost libraries
# check version using scram tool info boost
#INC += -I/cvmfs/cms.cern.ch/slc6_amd64_gcc491/external/boost/1.57.0-jlbgio/include
INC += -I$(CMSSW_FWLITE_INCLUDE_PATH)
#LDFLAGS += -L$(CMSSW_RELEASE_BASE)/external/slc6_amd64_gcc491/lib/ -lboost_program_options -#lboost_date_time -lboost_iostreams
LDFLAGS += -L$(LD_LIBRARY_PATH) -lboost_program_options -lboost_date_time -lboost_iostreams

SOURCES = Muon.cc MuonSelector.cc MuonHistos.cc Jet.cc JetHistos.cc
#OBJECTS = $(SOURCES:.C=.o)
#OBJECTS += $(SOURCES:.cc=.o)
OBJECTS = Muon.o MuonSelector.o MuonHistos.o Jet.o JetHistos.o
#EXECUTABLE = tanalyzer


all: $(SOURCES) muon.so

print-%  : ; @echo $* = $($*)

tanalyzer: $(OBJECTS)
	$(CC) -o tanalyzer $(LDFLAGS) $(INC) $(CFLAGS) $(OBJECTS) tanalyzer.cc

#$(EXCUTABLE): $(OBJECTS)
#	$(CC) -o $(EXECUTABLE) $(LDFLAGS) $(INC) $(CFLAGS) $(OBJECTS)

#muon.so: $(OBJECTS)
#	$(CC) -shared $(LDFLAGS) -Wl,--no-undefined $(INC) $(CFLAGS) $(OBJECTS) -o $@

.C.o:
	$(CC) -c $(INC) $(CFLAGS) $< -o $@

.cc.o:
	$(CC) -c $(INC) $(CFLAGS) $< -o $@

clean:
	rm -f *.o

cleanall: clean
	rm -f tanalyzer
