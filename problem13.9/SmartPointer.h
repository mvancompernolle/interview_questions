#include <iostream>

template <class T> 
class SmartPointer{
public:
	SmartPointer(T* ptr){
		ref = ptr;
		ref_count = new unsigned int;
		*ref_count = 1;
	}	

	SmartPointer(SmartPointer<T>& sptr){
		ref = sptr.ref;
		ref_count = sptr.ref_count;
		++*ref_count;
	}

	~SmartPointer(){
		--*ref_count;
		if(*ref_count == 0){
			delete ref;
			delete ref_count;
			ref = NULL;
			ref_count = NULL;
			std::cout << "deleting" << std::endl;
		}
	}

	SmartPointer<T>& operator=(SmartPointer<T>& sptr){
		if(this != &sptr){
			// delete object if was last one pointing to it
			--*ref_count;
			if(*ref_count == 0){
				delete ref;
				delete ref_count;
				std::cout << "deleting" << std::endl;
			}		

			ref = sptr.ref;
			ref_count = sptr.ref_count;
			++*ref_count;
		}
		return *this;
	}
	
	T getValue(){
		return *ref;
	}

protected:
	T* ref;
	unsigned int* ref_count;
};