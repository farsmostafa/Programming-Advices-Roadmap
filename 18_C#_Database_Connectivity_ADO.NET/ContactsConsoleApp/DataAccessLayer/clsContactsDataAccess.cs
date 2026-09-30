using System;
using System.Data;
using System.Data.SqlClient;

namespace DataAccessLayer
{
    public class clsContactsDataAccess
    {
        public static bool GetContactInfoByID(int ID, ref string FirstName, ref string LastName,
                        ref string Email, ref string Phone, ref string Address, ref DateTime DateOfBirth,
                        ref int CountryID, ref string ImagePath)
        {
            bool isFound = false;


            SqlConnection conn = new SqlConnection(clsDataAccessSettings.ConnectionString);

            string query = "Select * From Contacts Where ContactID = @ContactID";

            SqlCommand cmd = new SqlCommand(query, conn);
            cmd.Parameters.AddWithValue("@ContactID", ID);

            try
            {
                conn.Open();

                SqlDataReader reader = cmd.ExecuteReader();

                if (reader.Read())
                {
                    isFound = true;

                    FirstName = (string)reader["FirstName"];
                    LastName = (string)reader["LastName"];
                    Email = (string)reader["Email"];
                    Phone = (string)reader["Phone"];
                    Address = (string)reader["Address"];
                    DateOfBirth = (DateTime)reader["DateOfBirth"];
                    CountryID = (int)reader["CountryID"];
                    // Check Null Values
                    if (reader["ImagePath"] != DBNull.Value)
                        ImagePath = (string)reader["ImagePath"];
                    else
                        ImagePath = "";
                }
                else
                {
                    isFound = false;
                }
                reader.Close();
            }
            catch (Exception)
            {
                isFound = false;
            }
            finally
            {
                conn.Close();
            }

            return isFound;
        }


        public static int AddNewContact(string FirstName, string LastName,
                             string Email, string Phone, string Address, DateTime DateOfBirth,
                             int CountryID, string ImagePath)
        {
            int ID = -1;
            SqlConnection conn = new SqlConnection(clsDataAccessSettings.ConnectionString);

            string query = @"INSERT INTO Contacts(FirstName, LastName, Email, Phone, Address,DateOfBirth, CountryID,ImagePath)
	                         VALUES(@FirstName,@LastName,@Email,@Phone,@Address,@DateOfBirth,@CountryID,@ImagePath);
                             Select Scope_Identity();";

            SqlCommand cmd = new SqlCommand(query, conn);

            cmd.Parameters.AddWithValue("@FirstName", FirstName);
            cmd.Parameters.AddWithValue("@LastName", LastName);
            cmd.Parameters.AddWithValue("@Email", Email);
            cmd.Parameters.AddWithValue("@Phone", Phone);
            cmd.Parameters.AddWithValue("@Address", Address);
            cmd.Parameters.AddWithValue("@DateOfBirth", DateOfBirth);
            cmd.Parameters.AddWithValue("@CountryID", CountryID);
            if (ImagePath != "")
                cmd.Parameters.AddWithValue("@ImagePath", ImagePath);
            else
                cmd.Parameters.AddWithValue("@ImagePath", System.DBNull.Value);

            try
            {
                conn.Open();

                object result = cmd.ExecuteScalar();

                if (result != null && int.TryParse(result.ToString(), out int insertedID))
                {
                    ID = insertedID;
                }


            }
            catch (Exception)
            {
            }
            finally
            {
                conn.Close();
            }

            return ID;
        }

        public static bool UpdateContact(int ID, string FirstName, string LastName,
                             string Email, string Phone, string Address, DateTime DateOfBirth,
                             int CountryID, string ImagePath)
        {
            int rowsAffected = 0;
            SqlConnection conn = new SqlConnection(clsDataAccessSettings.ConnectionString);

            string query = @"UPDATE Contacts
                             SET FirstName = @FirstName
                                ,LastName = @LastName
                                ,Email = @Email
                                ,Phone = @Phone
                                ,Address = @Address
                                 ,DateOfBirth = @DateOfBirth
                                ,CountryID = @CountryID
                                ,ImagePath = @ImagePath
                             WHERE ContactID = @ContactID ";

            SqlCommand cmd = new SqlCommand(query, conn);

            cmd.Parameters.AddWithValue("@ContactID", ID);
            cmd.Parameters.AddWithValue("@FirstName", FirstName);
            cmd.Parameters.AddWithValue("@LastName", LastName);
            cmd.Parameters.AddWithValue("@Email", Email);
            cmd.Parameters.AddWithValue("@Phone", Phone);
            cmd.Parameters.AddWithValue("@Address", Address);
            cmd.Parameters.AddWithValue("@DateOfBirth", DateOfBirth);
            cmd.Parameters.AddWithValue("@CountryID", CountryID);
            if (ImagePath != "")
                cmd.Parameters.AddWithValue("@ImagePath", ImagePath);
            else
                cmd.Parameters.AddWithValue("@ImagePath", System.DBNull.Value);


            try
            {
                conn.Open();
                rowsAffected = cmd.ExecuteNonQuery();
            }
            catch (Exception)
            {
                return false;
            }
            finally
            {
                conn.Close();
            }

            return (rowsAffected > 0);
        }

        public static bool DeleteContact(int ID)
        {
            int rowsAffected = 0;
            SqlConnection conn = new SqlConnection(clsDataAccessSettings.ConnectionString);

            string query = @"Delete Contacts
                                 WHERE ContactID = @ContactID ";
            SqlCommand cmd = new SqlCommand(query, conn);

            cmd.Parameters.AddWithValue("@ContactID", ID);

            try
            {
                conn.Open();
                rowsAffected = cmd.ExecuteNonQuery();

            }
            catch (Exception)
            {
            }
            finally
            {
                conn.Close();
            }


            return rowsAffected > 0;
        }

        public static DataTable GetAllContacts()
        {
            DataTable dt = new DataTable();

            SqlConnection conn = new SqlConnection(clsDataAccessSettings.ConnectionString);

            string query = "Select * From Contacts";

            SqlCommand cmd = new SqlCommand(query, conn);

            try
            {
                conn.Open();

                SqlDataReader reader = cmd.ExecuteReader();

                if (reader.HasRows)
                {
                    dt.Load(reader);
                }
                reader.Close();
            }
            catch (Exception)
            {

            }
            finally
            {
                conn.Close();
            }

            return dt;
        }

        public static bool IsContactExist(int ID)
        {
            bool isFound = false;


            SqlConnection conn = new SqlConnection(clsDataAccessSettings.ConnectionString);

            string query = "Select Found=1 From Contacts Where ContactID = @ContactID";

            SqlCommand cmd = new SqlCommand(query, conn);
            cmd.Parameters.AddWithValue("@ContactID", ID);

            try
            {
                conn.Open();

                SqlDataReader reader = cmd.ExecuteReader();

                isFound = reader.HasRows;

                reader.Close();
            }
            catch (Exception)
            {
                isFound = false;
            }
            finally
            {
                conn.Close();
            }

            return isFound;
        }

    }

}
