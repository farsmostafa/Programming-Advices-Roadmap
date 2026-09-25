using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Net;
using System.Security.Policy;
using System.Text;
using System.Threading.Tasks;


namespace Training
{
    internal class Program
    {
        static string connectionString = "Server=.;Database=ContactsDB;Integrated Security=True;";

        struct stContact
        {
            public int ID { get; set; }
            public string FirstName { get; set; }
            public string LastName { get; set; }
            public string Email { get; set; }
            public string Phone { get; set; }
            public string Address { get; set; }
            public int CountryID { get; set; }
        }

        static void PrintContactRecord(stContact Contact)
        {
            Console.WriteLine("\nContact Info\n");
            Console.WriteLine($"Contact ID: {Contact.ID}");
            Console.WriteLine($"Name: {Contact.FirstName} {Contact.LastName}");
            Console.WriteLine($"Email: {Contact.Email}");
            Console.WriteLine($"Phone: {Contact.Phone}");
            Console.WriteLine($"Adress: {Contact.Address}");
            Console.WriteLine($"Country ID: {Contact.CountryID}");
            Console.WriteLine("\n");
        }

        static stContact ReadContact(string Title = "")
        {
            Console.WriteLine($"{Title}\n");
            stContact contact = new stContact();
            Console.Write("Enter First Name: ");
            contact.FirstName = Console.ReadLine();
            Console.Write("Enter Last Name: ");
            contact.LastName = Console.ReadLine();
            Console.Write("Enter Email: ");
            contact.Email = Console.ReadLine();
            Console.Write("Enter Phone: ");
            contact.Phone = Console.ReadLine();
            Console.Write("Enter Address: ");
            contact.Address = Console.ReadLine();
            Console.Write("Enter CounrtyID: ");
            contact.CountryID = int.Parse(Console.ReadLine());
            Console.WriteLine("\n");

            return contact;
        }

        static bool Add(stContact contact)
        {
            bool success = false;

            SqlConnection conn = new SqlConnection(connectionString);

            string query = @"INSERT INTO Contacts(FirstName, LastName, Email, Phone, Address, CountryID)
	                         VALUES(@FirstName,@LastName,@Email,@Phone,@Address,@CountryID)";

            SqlCommand cmd = new SqlCommand(query, conn);

            cmd.Parameters.AddWithValue("@FirstName", contact.FirstName);
            cmd.Parameters.AddWithValue("@LastName", contact.LastName);
            cmd.Parameters.AddWithValue("@Email", contact.Email);
            cmd.Parameters.AddWithValue("@Phone", contact.Phone);
            cmd.Parameters.AddWithValue("@Address", contact.Address);
            cmd.Parameters.AddWithValue("@CountryID", contact.CountryID);

            try
            {
                conn.Open();

                int rowsAffected = cmd.ExecuteNonQuery();

                if (rowsAffected > 0)
                {
                    success = true;
                }
                else
                {
                    success = false;
                }

                conn.Close();
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Error: {ex.Message}");
            }
            return success;
        }
        static bool Add(stContact contact, ref int ID)
        {
            bool success = false;

            SqlConnection conn = new SqlConnection(connectionString);

            string query = @"INSERT INTO Contacts(FirstName, LastName, Email, Phone, Address, CountryID)
	                         VALUES(@FirstName,@LastName,@Email,@Phone,@Address,@CountryID);
                             Select Scope_Identity();";

            SqlCommand cmd = new SqlCommand(query, conn);

            cmd.Parameters.AddWithValue("@FirstName", contact.FirstName);
            cmd.Parameters.AddWithValue("@LastName", contact.LastName);
            cmd.Parameters.AddWithValue("@Email", contact.Email);
            cmd.Parameters.AddWithValue("@Phone", contact.Phone);
            cmd.Parameters.AddWithValue("@Address", contact.Address);
            cmd.Parameters.AddWithValue("@CountryID", contact.CountryID);

            try
            {
                conn.Open();

                object result = cmd.ExecuteScalar();

                if (result != null && int.TryParse(result.ToString(), out ID))
                {
                    success = true;
                }
                else
                {
                    ID = -1;
                    success = false;
                }

                conn.Close();
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Error: {ex.Message}");
            }
            return success;
        }

        static bool GetSingleContactUsingReader(SqlConnection connection, SqlCommand command, ref stContact Contact)
        {

            bool isFound = false;
            try
            {
                connection.Open();
                SqlDataReader reader = command.ExecuteReader();


                if (reader.Read())
                {

                    Contact.ID = (int)reader["ContactID"];
                    Contact.FirstName = (string)reader["FirstName"];
                    Contact.LastName = (string)reader["LastName"];
                    Contact.Email = (string)reader["Email"];
                    Contact.Phone = (string)reader["Phone"];
                    Contact.Address = (string)reader["Address"];
                    Contact.CountryID = (int)reader["CountryID"];

                    isFound = true;
                }
                else
                {
                    isFound = false;
                }

                reader.Close();
                connection.Close();
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Error: {ex.Message}");
            }

            return isFound;
        }

        static bool Find(int ContactID, ref stContact Contact)
        {
            SqlConnection conn = new SqlConnection(connectionString);

            string query = "Select * From Contacts Where ContactID = @ContactID";
            SqlCommand cmd = new SqlCommand(query, conn);
            cmd.Parameters.AddWithValue("@ContactID", ContactID);

            if (GetSingleContactUsingReader(conn, cmd, ref Contact))
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        static bool Update(int ID)
        {
            bool Success = false;

            stContact Contact = new stContact();
            if (Find(ID, ref Contact))
            {
                PrintContactRecord(Contact);

                Contact = ReadContact("\nEnter Update Contact Info");

                SqlConnection conn = new SqlConnection(connectionString);

                string query = @"UPDATE Contacts
                             SET FirstName = @FirstName
                                ,LastName = @LastName
                                ,Email = @Email
                                ,Phone = @Phone
                                ,Address = @Address
                                ,CountryID = @CountryID
                             WHERE ContactID = @ContactID ";
                SqlCommand cmd = new SqlCommand(query, conn);

                cmd.Parameters.AddWithValue("@ContactID", ID);
                cmd.Parameters.AddWithValue("@FirstName", Contact.FirstName);
                cmd.Parameters.AddWithValue("@LastName", Contact.LastName);
                cmd.Parameters.AddWithValue("@Email", Contact.Email);
                cmd.Parameters.AddWithValue("@Phone", Contact.Phone);
                cmd.Parameters.AddWithValue("@Address", Contact.Address);
                cmd.Parameters.AddWithValue("@CountryID", Contact.CountryID);

                try
                {
                    conn.Open();
                    int rowsAffected = cmd.ExecuteNonQuery();

                    if (rowsAffected > 0)
                    {
                        Success = true;
                    }
                    else
                    {
                        Success = false;
                    }
                    conn.Close();
                }
                catch (Exception ex)
                {
                    Console.WriteLine($"Error: {ex.Message}");
                }

            }
            else
            {
                Console.WriteLine($"\nContact with ID [ {ID} ] is not found!");
            }

            return Success;
        }
        
        static bool Delete(int ID)
        {
            bool Success = false;

            stContact Contact = new stContact();
            if (Find(ID, ref Contact))
            {
                PrintContactRecord(Contact);

                SqlConnection conn = new SqlConnection(connectionString);

                string query = @"Delete Contacts
                                 WHERE ContactID = @ContactID ";
                SqlCommand cmd = new SqlCommand(query, conn);

                cmd.Parameters.AddWithValue("@ContactID", ID);

                try
                {
                    conn.Open();
                    int rowsAffected = cmd.ExecuteNonQuery();

                    if (rowsAffected > 0)
                    {
                        Success = true;
                    }
                    else
                    {
                        Success = false;
                    }
                    conn.Close();
                }
                catch (Exception ex)
                {
                    Console.WriteLine($"Error: {ex.Message}");
                }

            }
            else
            {
                Console.WriteLine($"\nContact with ID [ {ID} ] is not found!");
            }

            return Success;
        }

        static void GetAllContactsUsingReader(SqlConnection connection, SqlCommand command)
        {

            try
            {
                connection.Open();
                SqlDataReader reader = command.ExecuteReader();

                while (reader.Read())
                {
                    stContact Contact = new stContact();
                    Contact.ID = (int)reader["ContactID"];
                    Contact.FirstName = (string)reader["FirstName"];
                    Contact.LastName = (string)reader["LastName"];
                    Contact.Email = (string)reader["Email"];
                    Contact.Phone = (string)reader["Phone"];
                    Contact.Address = (string)reader["Address"];
                    Contact.CountryID = (int)reader["CountryID"];

                    PrintContactRecord(Contact);
                }

                reader.Close();
                connection.Close();
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Error: {ex.Message}");
            }


        }


        static void PrintAllContacts()
        {
            SqlConnection connection = new SqlConnection(connectionString);
            string query = "Select * From Contacts";
            SqlCommand command = new SqlCommand(query, connection);

            GetAllContactsUsingReader(connection, command);
        }

        static void PrintAllContactsWithFirstName(string FirstName)
        {
            SqlConnection connection = new SqlConnection(connectionString);
            string query = "select * From Contacts Where FirstName = @FirstName";

            SqlCommand command = new SqlCommand(query, connection);

            command.Parameters.AddWithValue("@FirstName", FirstName);

            GetAllContactsUsingReader(connection, command);
        }

        static void PrintAllContactsWithFirstNameAndCountry(string FirstName, int CountryID)
        {
            SqlConnection connection = new SqlConnection(connectionString);
            string query = "select * From Contacts Where FirstName = @FirstName and CountryID = @CountryID";

            SqlCommand command = new SqlCommand(query, connection);

            command.Parameters.AddWithValue("@FirstName", FirstName);
            command.Parameters.AddWithValue("@CountryID", CountryID);

            GetAllContactsUsingReader(connection, command);
        }

        static void SearchContactsStartsWith(string StartWith)
        {
            SqlConnection connection = new SqlConnection(connectionString);
            string query = "select * From Contacts Where FirstName Like  @StartWith + '%'";

            SqlCommand command = new SqlCommand(query, connection);

            command.Parameters.AddWithValue("@StartWith", StartWith);

            GetAllContactsUsingReader(connection, command);
        }

        static void SearchContactsEndsWith(string EndWith)
        {
            SqlConnection connection = new SqlConnection(connectionString);
            string query = "select * From Contacts Where FirstName Like  '%' + @EndWith  ";

            SqlCommand command = new SqlCommand(query, connection);

            command.Parameters.AddWithValue("@EndWith", EndWith);

            GetAllContactsUsingReader(connection, command);
        }

        static void SearchContactsContains(string Contains)
        {
            SqlConnection connection = new SqlConnection(connectionString);
            string query = "select * From Contacts Where FirstName Like  '%' + @Contains + '%' ";

            SqlCommand command = new SqlCommand(query, connection);

            command.Parameters.AddWithValue("@Contains", Contains);

            GetAllContactsUsingReader(connection, command);
        }

        static string GetFirstNameByContactIDUsingExecuteScalar(int ContactID)
        {
            String FirstName = "";
            SqlConnection conn = new SqlConnection(connectionString);

            string query = "Select FirstName From Contacts Where ContactID = @ContactID";

            SqlCommand cmd = new SqlCommand(query, conn);
            cmd.Parameters.AddWithValue("@ContactID", ContactID);

            try
            {
                conn.Open();

                object result = cmd.ExecuteScalar();

                if (result != null)
                {
                    FirstName = result.ToString();
                }
                else
                {
                    FirstName = "";
                }
                conn.Close();
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Error: {ex.Message}");
            }
            return FirstName;
        }

        static void FindContactByContactID(int ContactID)
        {
            stContact Contact = new stContact();
            if (Find(ContactID, ref Contact))
            {
                PrintContactRecord(Contact);
            }
            else
            {
                Console.WriteLine("Contact is NOT FOUND!!!");
                Console.WriteLine();
            }
        }

        static void AddNewContact()
        {
            stContact Contact = ReadContact("Enter New Contact Info");

            if (Add(Contact))
            {
                Console.WriteLine("Record iserted successfully.");
            }
            else
            {
                Console.WriteLine("Record insertion failed.");
            }
        }

        static void AddNewContactAndGetID()
        {
            stContact Contact = ReadContact("Enter New Contact Info");
            int ID = -1;
            if (Add(Contact, ref ID))
            {
                Console.WriteLine("Record iserted successfully.");
                Console.WriteLine($"Newly iserted ID: {ID}");
            }
            else
            {
                Console.WriteLine("Record insertion failed.");
            }
        }

        static void UpdateContactByID()
        {

            Console.Write("Enter Contact ID to Update: ");
            int.TryParse(Console.ReadLine(), out int ID);
            if (Update(ID))
            {
                Console.WriteLine("Record Updated successfully.");
            }
            else
            {
                Console.WriteLine("Record Update failed.");
            }

        }
        
        static void DeleteContactByID()
        {

            Console.Write("Enter Contact ID to Delete: ");
            int.TryParse(Console.ReadLine(), out int ID);
            if (Delete(ID))
            {
                Console.WriteLine("\n\nRecord Deleted successfully.\n\n");
            }
            else
            {
                Console.WriteLine("\n\nRecord Delete failed.\n\n");
            }

        }

        static void Main(string[] args)
        {
            PrintAllContacts();
            //PrintAllContactsWithFirstName("Fars");
            //PrintAllContactsWithFirstNameAndCountry("Jane",1);
            //SearchContactsStartsWith("J");
            //SearchContactsEndsWith("e");
            //SearchContactsContains("i");
            //Console.WriteLine(GetFirstNameByContactIDUsingExecuteScalar(1));
            //FindContactByContactID(1);
            //AddNewContact();
            //AddNewContactAndGetID();
            //UpdateContactByID();

            //DeleteContactByID();






            Console.ReadKey();
        }
    }
}
