# BugAndFix

To configure the project, just run the relevant [setup](Setup) file

# Coding conventions
Functions - CapitalCamelCase
Class - CapitalCamelCase
private member variables - m_Variables
static variables - s_Variables
function parameters - theVariable
global variables - CAPTIAL
const global variables - CAPTIAL
macro - CAPITAL (except) data type
variable - aVariable


# Structure
## Utils
### Macros
- max(a, b)
- min(a, b)
- negate(a)
- inverseSqrt(a)
- square(a)

### functions
- pow(a, b)

## Classes

class Matrix\<row, column, dataType\>
member data
- dataType\[row][column]

member function
- print()
- getRow(int)
- getColumn(int)
- operator+(Matrix)
- operator-(Matrix)
- operator\*(Matrix)
- operator\*(int)
- operator=(Matrix)
- operator==(Matrix)
- operator\[]\[](int, int)
- transpose
- trace // sum of diagonals
- inverse
- determinant
- rank
- norm
- eigenValues
- vector_product(Vector)

--------------------------------------------------

class Transform
member function
// will specialize these functions only for matrices but will call them for vectors
// also for errors
- scale(\<dataType>, \<dataType>) // potential error dataType should be compatible
- rotate(\<dataType>, \<dataType>)
- translate(\<dataType>, \<dataType>)

--------------------------------------------------

class Vector\<data, dataTypes\>
member data
- dataType[data]

member functions
- print
- operator+(Vector)
- operator-(Vector)
- operator=(Vector)
- operator==(Vector)
- operator\[](int)
- push_back()
- emplace_back()
- reserve()
- getSize()


------------------------------------------
specialized in vec2
- dot(Vector)
- cross(Vector)
- magnitude
- distance(Vector)
- emplace(...)

--------------------------------------------------
PHYSICS
--------------------------------------------------
class PhysicsObject: abstract
member data
position: vec2
velocity: vec2

member functions
set velocity
set position
update(Time t)

--------------------------------------------------

class PhysicsEngine
member data:
gravity: Vec2
Vector physicsObjs

member functions
set gravity
add physicsObjs
simulate(Time t)

--------------------------------------------------

class Collider: PhysicsObject
member data
Shape obj;

--------------------------------------------------
class Shape
member data
type

member function
get type()

--------------------------------------------------
enum Shape {
- ...
- ...
}

# Potential Errors

- if wrong_statements {} no else statements
- incorrect placement of \#error
- for loop i = 0 to i <= n will cause segmentation fault
