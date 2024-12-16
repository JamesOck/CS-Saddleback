import csv
import pickle

def load_students(file_path_csv='data/students.csv', file_path_dic='data/students.dic'):
    students = {}
    try:
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
            print(f"Both {file_path_csv} and {file_path_dic} are missing, exiting the application")
            exit(0)
    except KeyError as e:
        print(f"Error loading students: {e}")
        exit(0)
    return students

def load_courses(file_path_csv='data/courses.csv', file_path_dic='data/courses.dic'):
    courses = []
    try:
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
            print(f"Both {file_path_csv} and {file_path_dic} are missing, exiting the application")
            exit(0)
    except KeyError as e:
        print(f"Error loading courses: {e}")
        exit(0)
    return courses

def load_registrations(file_path_csv='data/registration.csv', file_path_dic='data/registration.dic'):
    registrations = []
    try:
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
            print(f"Both {file_path_csv} and {file_path_dic} are missing, exiting the application")
            exit(0)
    except KeyError as e:
        print(f"Error loading registrations: {e}")
        exit(0)
    return registrations

def save_registrations(registrations, file_path_csv='data/registration.csv', file_path_dic='data/registration.dic'):
    try:
        with open(file_path_csv, mode='w', newline='') as file:
            fieldnames = ['student_id', 'ticket_no']
            writer = csv.DictWriter(file, fieldnames=fieldnames)
            writer.writeheader()
            for registration in registrations:
                writer.writerow(registration)
        with open(file_path_dic, mode='w', newline='') as file:
            writer = csv.writer(file)
            for registration in registrations:
                writer.writerow([registration['student_id'], registration['ticket_no']])
    except Exception as e:
        print(f"Error saving registrations: {e}")
