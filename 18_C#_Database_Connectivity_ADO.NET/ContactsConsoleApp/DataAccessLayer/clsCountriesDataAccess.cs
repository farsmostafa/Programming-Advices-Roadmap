using System;
using System.Data;
using System.Data.SqlClient;

namespace DataAccessLayer
{
    public class clsCountriesDataAccess
    {
        public static bool GetCountryInfoByID(int ID, ref string CountryName, ref string Code, ref string PhoneCode)
        {
            bool isFound = false;


            SqlConnection conn = new SqlConnection(clsDataAccessSettings.ConnectionString);

            string query = "Select * From Countries Where CountryID = @CountryID";

            SqlCommand cmd = new SqlCommand(query, conn);
            cmd.Parameters.AddWithValue("@CountryID", ID);

            try
            {
                conn.Open();

                SqlDataReader reader = cmd.ExecuteReader();

                if (reader.Read())
                {
                    isFound = true;

                    CountryName = (string)reader["CountryName"];

                    if (reader["Code"] != DBNull.Value)
                        Code = (string)reader["Code"];
                    else
                        Code = "";

                    if (reader["PhoneCode"] != DBNull.Value)
                        PhoneCode = (string)reader["PhoneCode"];
                    else
                        PhoneCode = "";
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

        public static bool GetCountryInfoByName(ref int ID, string CountryName, ref string Code, ref string PhoneCode)
        {
            bool isFound = false;


            SqlConnection conn = new SqlConnection(clsDataAccessSettings.ConnectionString);

            string query = "Select * From Countries Where CountryName = @CountryName";

            SqlCommand cmd = new SqlCommand(query, conn);
            cmd.Parameters.AddWithValue("@CountryName", CountryName);

            try
            {
                conn.Open();

                SqlDataReader reader = cmd.ExecuteReader();

                if (reader.Read())
                {
                    isFound = true;

                    ID = (int)reader["CountryID"];

                    if (reader["Code"] != DBNull.Value)
                        Code = (string)reader["Code"];
                    else
                        Code = "";

                    if (reader["PhoneCode"] != DBNull.Value)
                        PhoneCode = (string)reader["PhoneCode"];
                    else
                        PhoneCode = "";
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

        public static int AddNewCountry(string CountryName, string Code, string PhoneCode)
        {
            int ID = -1;
            SqlConnection conn = new SqlConnection(clsDataAccessSettings.ConnectionString);

            string query = @"INSERT INTO Countries(CountryName, Code, PhoneCode)
	                         VALUES(@CountryName, @Code, @PhoneCode);
                             Select Scope_Identity();";

            SqlCommand cmd = new SqlCommand(query, conn);

            cmd.Parameters.AddWithValue("@CountryName", CountryName);

            if (Code != "")
                cmd.Parameters.AddWithValue("@Code", Code);
            else
                cmd.Parameters.AddWithValue("@Code", System.DBNull.Value);

            if (PhoneCode != "")
                cmd.Parameters.AddWithValue("@PhoneCode", PhoneCode);
            else
                cmd.Parameters.AddWithValue("@PhoneCode", System.DBNull.Value);


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

        public static bool UpdateCountry(int ID, string CountryName, string Code, string PhoneCode)
        {
            int rowsAffected = 0;
            SqlConnection conn = new SqlConnection(clsDataAccessSettings.ConnectionString);

            string query = @"UPDATE Countries
                             SET CountryName = @CountryName
                                ,Code = @Code
                                ,PhoneCode = @PhoneCode
                             WHERE CountryID = @CountryID ";

            SqlCommand cmd = new SqlCommand(query, conn);

            cmd.Parameters.AddWithValue("@CountryID", ID);
            cmd.Parameters.AddWithValue("@CountryName", CountryName);

            if (Code != "")
                cmd.Parameters.AddWithValue("@Code", Code);
            else
                cmd.Parameters.AddWithValue("@Code", System.DBNull.Value);

            if (PhoneCode != "")
                cmd.Parameters.AddWithValue("@PhoneCode", PhoneCode);
            else
                cmd.Parameters.AddWithValue("@PhoneCode", System.DBNull.Value);


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

        public static bool DeleteCountry(int ID)
        {
            int rowsAffected = 0;
            SqlConnection conn = new SqlConnection(clsDataAccessSettings.ConnectionString);

            string query = @"Delete Countries
                                 WHERE CountryID = @CountryID ";
            SqlCommand cmd = new SqlCommand(query, conn);

            cmd.Parameters.AddWithValue("@CountryID", ID);

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


            return rowsAffected > 0;
        }

        public static DataTable GetAllCountries()
        {
            DataTable dt = new DataTable();

            SqlConnection conn = new SqlConnection(clsDataAccessSettings.ConnectionString);

            string query = "Select * From Countries order by CountryName";

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

        public static bool IsCountryExist(int ID)
        {
            bool isFound = false;


            SqlConnection conn = new SqlConnection(clsDataAccessSettings.ConnectionString);

            string query = "Select Found=1 From Countries Where CountryID = @CountryID";

            SqlCommand cmd = new SqlCommand(query, conn);
            cmd.Parameters.AddWithValue("@CountryID", ID);

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

        public static bool IsCountryExist(string CountryName)
        {
            bool isFound = false;


            SqlConnection conn = new SqlConnection(clsDataAccessSettings.ConnectionString);

            string query = "Select Found=1 From Countries Where CountryName = @CountryName";

            SqlCommand cmd = new SqlCommand(query, conn);
            cmd.Parameters.AddWithValue("@CountryName", CountryName);

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
