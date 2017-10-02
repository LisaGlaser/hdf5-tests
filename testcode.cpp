/************************************************
* this code is my utter mess of just            *
* checking stuff out and getting hdf5 working   *
* and me that's Lisa Glaser                     *
************************************************/

// stuff I copied from create.cpp as a start
#include <iostream>
#include <string>
#include <vector>
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
  int Nsweeps=5;
  int Nmat=3;
  int Nele=2;
	dims[0] = Nsweeps;                 // number of sweeps/ saves
	dims[1] = Nmat;                 // number of matrices
	dims[2] = Nele;                 // number of elements per matrix ? (check how the hdf5/ eigen wrapper works)

  int RANK=3;
	DataSpace dataspace(RANK, dims);

	// Create the dataset.
	DataSet dataset = file.createDataSet(DATASET_NAME, std::vector<int>, dataspace);

  // now fill in each sweep, here let's do it easily
  // now each sweep contains 3 matrices which are played by 2 element arrays

//  int mat[3][2]={{2222,2},{2,2},{2,2}};
  std::vector<int> matrix;
  std::vector< std::vector<int> > matrices;
  //std::vector<std::vector<std::vector<int> > > mydata;

  for(int i=0;i<Nele;i++) matrix.push_back(3);

  for(int i=0;i<Nmat;i++) matrices.push_back(matrix);

  for(int i=0;i<Nsweeps;i++)
  {
  //  mydata.push_back(matrix);
  dataset.write(matrix,std::vector<int>);
  }

//  dataset.write(mydata,PredType::NATIVE_INT);

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
