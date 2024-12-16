import datetime
from data_utils import load_students, load_courses, load_registrations, save_registrations

# Function to greet the user based on the current time of day
def greet_user(student_name):
    """
    Greet the user based on the current time of day.
    student_name: The name of the student.
    """
    current_hour = datetime.datetime.now().hour
    if 0 <= current_hour < 12:
        greeting = "Good Morning"
    elif 12 <= current_hour < 17:
        greeting = "Good Afternoon"
    else:
        greeting = "Good Evening"
    print(f"{greeting} {student_name.title()}, what would you like to do today?")

# Function to display the main menu options
def display_menu():
    """
    Display the main menu options.
    """
    print("""
    list     - Full course listing
    detail   - Course detail information
    info     - Student information
    register - Register for a class
    drop     - Drop a class
    menu     - Display menu
    exit     - End session
    """)

# Function to list all courses sorted by ticket number or course code
def list_courses(courses):
    """
    List all courses sorted by ticket number or course code.
    courses: List of course data.
    """
    sort_option = input("Sort by ticket # or course code (t/c): ").strip().lower()
    if sort_option == 't':
        courses.sort(key=lambda x: x['ticket'])
        print("Course Listing by Ticket Number")
    elif sort_option == 'c':
        courses.sort(key=lambda x: x['code'])
        print("Course Listing by Course Code")
    else:
        print("Invalid sort option.")
        return

    print("Ticket Code      Course Name                                  Units Day    Time           Instructor")
    print("=" * 95)
    for course in courses:
        print(
            f"{course['ticket']:7} {course['code']:9} {course['course_name'][:45]:45} {course['units']:5} {course['day']:6} {course['time']:14} {course['instructor']:15}")
    print(f"{len(courses)} Courses")

# Function to display detailed information for a specific course
def course_detail(courses, registrations):
    """
    Display detailed information for a specific course.
    courses: List of course data.
    registrations: List of registration data.
    """
    ticket_number = input("Enter course ticket # (or 'exit'): ").strip()
    if ticket_number.lower() == 'exit':
        return

    course = next((course for course in courses if course['ticket'] == ticket_number), None)
    if not course:
        print(f"{ticket_number} not found")
        return

    print(f"Code: {course['code']} Course Name: {course['course_name']}")
    print(f"Units: {course['units']} Day: {course['day']} Time: {course['time']}")
    print(f"Instructor: {course['instructor']}")
    print("\nEnrolled Students")
    print("=" * 50)

    enrolled_students = [reg for reg in registrations if reg['ticket_no'] == ticket_number]
    for reg in enrolled_students:
        print(
            f"{reg['student_id']:13} {students[reg['student_id']]['last_name']:16} {students[reg['student_id']]['first_name']:11}")
    print(f"Total Students Registered: {len(enrolled_students)}")

# Function to display information for the logged-in student
def student_info(student_id, registrations, courses):
    """
    Display information for the logged-in student.
    student_id: The ID of the logged-in student.
    registrations: List of registration data.
    courses: List of course data.
    """
    student = students[student_id]
    print(f"Student ID: {student_id}")
    print(f"{student['last_name'].title()}, {student['first_name'].title()}\n")

    student_courses = [reg for reg in registrations if reg['student_id'] == student_id]
    print("Registered Courses")
    print("Ticket Code       Course Name                                  Units Day    Time         Instructor")
    print("=" * 95)

    total_units = 0
    for reg in student_courses:
        course = next((course for course in courses if course['ticket'] == reg['ticket_no']), None)
        if course:
            total_units += float(course['units'])
            print(
                f"{course['ticket']:7} {course['code']:9} {course['course_name'][:45]:45} {course['units']:5} {course['day']:6} {course['time']:14} {course['instructor']:15}")
    print(f"{len(student_courses)} Course(s) Registered                                  Units:   {total_units}")

# Function to register the logged-in student for a course
def register_course(student_id, registrations, courses):
    """
    Register the logged-in student for a course.
    student_id: The ID of the logged-in student.
    registrations: List of registration data.
    courses: List of course data.
    """
    ticket_number = input("Enter course ticket # (or 'exit'): ").strip()
    if ticket_number.lower() == 'exit':
        return

    # Check if the student is already registered for the course
    if any(reg['ticket_no'] == ticket_number and reg['student_id'] == student_id for reg in registrations):
        print(f"{student_id} is already registered in {ticket_number}")
        return

    course = next((course for course in courses if course['ticket'] == ticket_number), None)
    if not course:
        print(f"{ticket_number} not found")
        return

    # Check if total units will exceed the limit of 12
    student_courses = [reg for reg in registrations if reg['student_id'] == student_id]
    total_units = sum(
        float(course['units']) for reg in student_courses for course in courses if course['ticket'] == reg['ticket_no'])
    if total_units + float(course['units']) > 12:
        print("This would exceed the maximum number of units allowed.")
        return

    enrolled_students = [reg for reg in registrations if reg['ticket_no'] == ticket_number]
    if len(enrolled_students) >= 15:
        print(f"{ticket_number} is full.")
        return

    # Register the student for the course
    registrations.append({'student_id': student_id, 'ticket_no': ticket_number})
    save_registrations(registrations)
    print(f"{student_id} was added to {ticket_number}")

# Function to drop a course for the logged-in student
def drop_course(student_id, registrations):
    """
    Drop a course for the logged-in student.
    :param student_id: The ID of the logged-in student.
    :param registrations: List of registration data.
    """
    ticket_number = input("Enter course ticket # (or 'exit'): ").strip()
    if ticket_number.lower() == 'exit':
        return

    registration = next(
        (reg for reg in registrations if reg['ticket_no'] == ticket_number and reg['student_id'] == student_id), None)
    if not registration:
        print(f"{ticket_number} not found or {student_id} is not enrolled in {ticket_number}")
        return

    registrations.remove(registration)
    save_registrations(registrations)
    print(f"{student_id} was dropped from {ticket_number}")

# Main function to run the Saddleback College Registration application
def main():
    """
    Main function to run the Saddleback College Registration application.
    """
    global students, courses, registrations
    students = load_students()
    courses = load_courses()
    registrations = load_registrations()

    print("Saddleback College Registration")
    while True:
        student_id = input("Enter Student ID (or 'exit' to exit the application): ").strip()
        if student_id.lower() == 'exit':
            print("Session ended.")
            break

        if student_id in students:
            student_name = students[student_id]['first_name']
            greet_user(student_name)
            display_menu()

            while True:
                selection = input("Enter selection: ").strip().lower()
                if selection == 'exit':
                    print("Session ended.")
                    return
                elif selection == 'menu':
                    display_menu()
                elif selection == 'list':
                    list_courses(courses)
                elif selection == 'detail':
                    course_detail(courses, registrations)
                elif selection == 'info':
                    student_info(student_id, registrations, courses)
                elif selection == 'register':
                    register_course(student_id, registrations, courses)
                elif selection == 'drop':
                    drop_course(student_id, registrations)
                else:
                    print("Invalid selection, please try again.")
        else:
            print("Student ID not found, please try again.")

if __name__ == "__main__":
    main()
