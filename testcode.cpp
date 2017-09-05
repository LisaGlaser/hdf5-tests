/************************************************
* this code is my utter mess of just            *
* checking stuff out and getting hdf5 working   *
* and me that's Lisa Glaser                     *
************************************************/

// stuff I copied from create.cpp as a start
#include <iostream>
#include <string>
#include "H5Cpp.h"
using namespace H5;


int main (void)
{
    // Try block to detect exceptions raised by any of the calls inside it
    try
    {
	// Turn off the auto-printing when failure occurs so that we can
	// handle the errors appropriately
	Exception::dontPrint();

  H5std_string	FILE_NAME("lisas_data.h5");
  H5std_string	DATASET_NAME("geometry");

	// Create a new file using the default property lists.
	H5File file(FILE_NAME, H5F_ACC_TRUNC);

	// Create the data space for the dataset.
	hsize_t dims[3];               // dataset dimensions
	dims[0] = 4;                 // each line has this many entries
	dims[1] = 5;                 // number of lines
	dims[2] = 2;                 // number of lines
  int RANK=3;
	DataSpace dataspace(RANK, dims);

	// Create the dataset.
	DataSet dataset = file.createDataSet(DATASET_NAME, PredType::STD_I32BE, dataspace);

    }  // end of try block

    // catch failure caused by the H5File operations00
    catch(FileIException error)
    {
	error.printError();
	return -1;
    }

    // catch failure caused by the DataSet operations
    catch(DataSetIException error)
    {
	error.printError();
	return -1;
    }

    // catch failure caused by the DataSpace operations
    catch(DataSpaceIException error)
    {
	error.printError();
	return -1;
    }

    return 0;  // successfully terminated
}
