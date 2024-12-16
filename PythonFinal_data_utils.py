import csv
import pickle

# Function to load student data from a CSV or dictionary file
def load_students(file_path_csv='data/students.csv', file_path_dic='data/students.dic'):
    """
    Load student data from a CSV file, or if not found, from a dictionary file.
    If neither file exists, exit the application.
    
    :param file_path_csv: Path to the students CSV file.
    :param file_path_dic: Path to the students dictionary file.
    :return: Dictionary of students with student_id as keys.
    """
    students = {}
    try:
        # Try loading from CSV
        with open(file_path_csv, mode='r') as file:
            reader = csv.reader(file)
            headers = ['student_id', 'last_name', 'first_name']
            for row in reader:
                if len(row) == len(headers):
                    student_id, last_name, first_name = row
                    students[student_id] = {
                        'first_name': first_name,
                        'last_name': last_name
                    }
                else:
                    raise KeyError("Missing required keys in students CSV file")
    except FileNotFoundError:
        # If CSV not found, try loading from dictionary
        try:
            with open(file_path_dic, mode='r') as file:
                reader = csv.reader(file)
                headers = ['student_id', 'last_name', 'first_name']
                for row in reader:
                    if len(row) == len(headers):
                        student_id, last_name, first_name = row
                        students[student_id] = {
                            'first_name': first_name,
                            'last_name': last_name
                        }
                    else:
                        raise KeyError("Missing required keys in students dictionary file")
        except FileNotFoundError:
            # If both files are missing, exit the application
            print(f"Both {file_path_csv} and {file_path_dic} are missing, exiting the application")
            exit(0)
    except KeyError as e:
        # Handle cases where required fields are missing in files
        print(f"Error loading students: {e}")
        exit(0)
    return students

# Function to load course data from a CSV or dictionary file
def load_courses(file_path_csv='data/courses.csv', file_path_dic='data/courses.dic'):
    """
    Load course data from a CSV file, or if not found, from a dictionary file.
    If neither file exists, exit the application.
    
    :param file_path_csv: Path to the courses CSV file.
    :param file_path_dic: Path to the courses dictionary file.
    :return: List of course dictionaries.
    """
    courses = []
    try:
        # Try loading from CSV
        with open(file_path_csv, mode='r') as file:
            reader = csv.reader(file)
            headers = ['ticket', 'code', 'course_name', 'units', 'day', 'time', 'instructor']
            for row in reader:
                if len(row) == len(headers):
                    course = dict(zip(headers, row))
                    courses.append(course)
                else:
                    raise KeyError("Missing required keys in courses CSV file")
    except FileNotFoundError:
        # If CSV not found, try loading from dictionary
        try:
            with open(file_path_dic, mode='r') as file:
                reader = csv.reader(file)
                headers = ['ticket', 'code', 'course_name', 'units', 'day', 'time', 'instructor']
                for row in reader:
                    if len(row) == len(headers):
                        course = dict(zip(headers, row))
                        courses.append(course)
                    else:
                        raise KeyError("Missing required keys in courses dictionary file")
        except FileNotFoundError:
            # If both files are missing, exit the application
            print(f"Both {file_path_csv} and {file_path_dic} are missing, exiting the application")
            exit(0)
    except KeyError as e:
        # Handle cases where required fields are missing in files
        print(f"Error loading courses: {e}")
        exit(0)
    return courses

# Function to load registration data from a CSV or dictionary file
def load_registrations(file_path_csv='data/registration.csv', file_path_dic='data/registration.dic'):
    """
    Load registration data from a CSV file, or if not found, from a dictionary file.
    If neither file exists, exit the application.
    
    :param file_path_csv: Path to the registrations CSV file.
    :param file_path_dic: Path to the registrations dictionary file.
    :return: List of registration dictionaries.
    """
    registrations = []
    try:
        # Try loading from CSV
        with open(file_path_csv, mode='r') as file:
            reader = csv.reader(file)
            headers = ['student_id', 'ticket_no']
            for row in reader:
                if len(row) == len(headers):
                    registration = dict(zip(headers, row))
                    registrations.append(registration)
                else:
                    raise KeyError("Missing required keys in registrations CSV file")
    except FileNotFoundError:
        # If CSV not found, try loading from dictionary
        try:
            with open(file_path_dic, mode='r') as file:
                reader = csv.reader(file)
                headers = ['student_id', 'ticket_no']
                for row in reader:
                    if len(row) == len(headers):
                        registration = dict(zip(headers, row))
                        registrations.append(registration)
                    else:
                        raise KeyError("Missing required keys in registrations dictionary file")
        except FileNotFoundError:
            # If both files are missing, exit the application
            print(f"Both {file_path_csv} and {file_path_dic} are missing, exiting the application")
            exit(0)
    except KeyError as e:
        # Handle cases where required fields are missing in files
        print(f"Error loading registrations: {e}")
        exit(0)
    return registrations

# Function to save registration data to CSV and dictionary formats
def save_registrations(registrations, file_path_csv='data/registration.csv', file_path_dic='data/registration.dic'):
    """
    Save registration data to a CSV file and a dictionary file.
    
    :param registrations: List of registration dictionaries.
    :param file_path_csv: Path to save registrations as a CSV file.
    :param file_path_dic: Path to save registrations as a dictionary file.
    """
    try:
        # Save to CSV
        with open(file_path_csv, mode='w', newline='') as file:
            fieldnames = ['student_id', 'ticket_no']
            writer = csv.DictWriter(file, fieldnames=fieldnames)
            writer.writeheader()
            for registration in registrations:
                writer.writerow(registration)
        
        # Save to dictionary file
        with open(file_path_dic, mode='w', newline='') as file:
            writer = csv.writer(file)
            for registration in registrations:
                writer.writerow([registration['student_id'], registration['ticket_no']])
    except Exception as e:
        print(f"Error saving registrations: {e}")
