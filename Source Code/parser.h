/*!
 * \class Parser
 * \brief  The class managing the parser for the shapes database.
*/

#ifndef PARSER_H
#define PARSER_H

#include "libraries.h"
#include "shape_list.h"
#include "qtconversions.h"
#include "shapeexception.h"
#include <sstream>

using namespace std;

/*! This class purely reads in shape information from a text file and populates a vector of Shape pointers to be returned by reference to the controller class, AllShapes.
 */
class Parser
{
public:

    //! Default constructor
    Parser() {}

    //! Destructor
    ~Parser() {}

    //! Gets a single line from the input file.
    /*! Reads in each line of the input file as one string, then parses it individually for information.
     * \param file the input filestream variable
     * \returns The relevant parsed data as a string
     */
    string getStringFromFile(fstream &file);

    //! Reads in shapes and populates the shape vector from a file
    /*! Reads through the entire file and populates the shape vector with Shape pointers holding shape specifications and properties.
     * Tracks the number of shapes that are entering the vector.
     * \param v_shapes the vector of Shape pointers, passed in by reference
     * \param device the pointer to the QPaintDevice
     * \sa AllShapes::addShapesFromFile()
     * \returns The number of shapes in the vector.
     */
    int parseShapes(myVector::vector<Shape*> &v_shapes, QPaintDevice *device);

    //! Creates a pointer of type Shape that relates to a specific derived class object via inheritance & polymorphism
    /*! Depending on the type of shape dictated in the file, returns a pointer to that type of shape.
     * \param shapeType the type of shape, as a string
     * \param device the pointer to the QPaintDevice
     * \returns The Shape pointer to the specific shape dictated by shapeType.
     */
    Shape* getShapePtr(std::string shapeType, QPaintDevice *device);
};

#endif // PARSER_H
