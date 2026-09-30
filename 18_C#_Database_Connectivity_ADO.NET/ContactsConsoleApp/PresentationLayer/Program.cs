using System;
using System.Data;
using BusinessLayer;

namespace PresentationLayer
{
    internal class Program
    {
        public static void PrintContactCard(clsContact Contact)
        {
            Console.WriteLine("\n------------------------------------\n");
            Console.WriteLine("Contact Info :-\n");
            Console.WriteLine($"Contact ID    : {Contact.ID}");
            Console.WriteLine($"Name          : {Contact.FirstName} {Contact.LastName}");
            Console.WriteLine($"Email         : {Contact.Email}");
            Console.WriteLine($"Phone         : {Contact.Phone}");
            Console.WriteLine($"Adress        : {Contact.Address}");
            Console.WriteLine($"Date Of Birth : {Contact.DateOfBirth}");
            Console.WriteLine($"Country ID    : {Contact.CountryID}");
            Console.WriteLine($"Image Path    : {Contact.ImagePath}");
            Console.WriteLine("\n------------------------------------\n");
            Console.WriteLine("\n");
        }

        public static void ReadContact(ref clsContact contact, string Title = "")
        {

            Console.WriteLine($"{Title}\n");
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
            Console.Write("Enter Date Of Birth [yyyy-mm-dd]: ");
            contact.DateOfBirth = DateTime.Parse(Console.ReadLine());
            Console.Write("Enter CounrtyID: ");
            contact.CountryID = int.Parse(Console.ReadLine());
            Console.Write("Enter Image Path: ");
            contact.ImagePath = Console.ReadLine();
            Console.WriteLine("\n");

        }

        static void testFindContact(int ID)
        {
            clsContact Contact1 = clsContact.Find(ID);

            if (Contact1 != null)
            {
                PrintContactCard(Contact1);
            }
            else
            {
                Console.WriteLine($"\nContact with ID [ {ID} ] is not found!");
            }

        }

        static void testAddNewContact()
        {
            clsContact contact = new clsContact();
            ReadContact(ref contact, "Enter New Contact Info");
            if (contact.Save())
            {
                Console.WriteLine($"Contact Added Successfully with ID = {contact.ID}");
                PrintContactCard(contact);
            }
            else
            {
                Console.WriteLine("Contact Adding Failed");
            }
        }

        static void testUpdateContact(int ID)
        {
            clsContact contact = clsContact.Find(ID);
            if (contact != null)
            {
                PrintContactCard(contact);
                ReadContact(ref contact, "Enter Update Contact Info");

                PrintContactCard(contact);
                if (contact.Save())
                {
                    Console.WriteLine($"Contact Updated Successfully");
                    PrintContactCard(contact);
                }
                else
                {
                    Console.WriteLine("Contact Updating Failed");
                }
            }
            else
            {
                Console.WriteLine($"\nContact with ID [ {ID} ] is not found!");
            }
        }

        static void testDeleteContact(int ID)
        {
            if (clsContact.IsContactExist(ID))
            {
                if (clsContact.DeleteContact(ID))
                {
                    Console.WriteLine($"Contact Deleted Successfully");
                }
                else
                {
                    Console.WriteLine("Contact Delete Failed");
                }
            }
            else
            {
                Console.WriteLine($"\nContact with ID [ {ID} ] is not found!");
            }
        }

        public static void PrintContactRow(DataRow contactRow)
        {

            string imagePath = contactRow["ImagePath"] != DBNull.Value ? contactRow["ImagePath"].ToString() : "N/A";

            // 2. Formatting Date to ignore time (if it's a valid date)
            string dob = Convert.ToDateTime(contactRow["DateOfBirth"]).ToString("yyyy-MM-dd");

            // 3. Combining First and Last Name for better display
            string fullName = $"{contactRow["FirstName"]} {contactRow["LastName"]}";

            // 4. Console output with specific padding (negative number means left-aligned)
            Console.WriteLine($"| {contactRow["ContactID"],-4} | {fullName,-20} | {contactRow["Phone"],-15} | {contactRow["Email"],-25} | {dob,-12} | {contactRow["CountryID"],-3} | {imagePath,-35} |");
        }

        static void ListContacts()
        {
            DataTable dataTable = clsContact.GetAllContacts();

            if (dataTable.Rows.Count > 0)
            {
                // Drawing Table Header
                Console.WriteLine("\n----------------------------------------------------------------------------------------------------------------------------------------");
                Console.WriteLine($"| {"ID",-4} | {"Full Name",-20} | {"Phone",-15} | {"Email",-25} | {"DOB",-12} | {"CID",-3} | {"Image Path",-35} |");
                Console.WriteLine("----------------------------------------------------------------------------------------------------------------------------------------");

                foreach (DataRow row in dataTable.Rows)
                {
                    PrintContactRow(row);
                }

                // Drawing Table Footer
                Console.WriteLine("----------------------------------------------------------------------------------------------------------------------------------------\n");
            }
            else
            {
                Console.WriteLine("No Contacts Found.");
            }
        }

        static void testIsContactExist(int ID)
        {
            if (clsContact.IsContactExist(ID))
            {
                Console.WriteLine("Yes, Contact is there.");
            }
            else
            {
                Console.WriteLine("No, Contact is not there.");
            }
        }




        public static void PrintCountryCard(clsCountry Country)
        {
            Console.WriteLine("\n------------------------------------\n");
            Console.WriteLine("Country Info :-\n");
            Console.WriteLine($"Country ID : {Country.ID}");
            Console.WriteLine($"Name       : {Country.CountryName}");
            Console.WriteLine($"Code       : {(string.IsNullOrEmpty(Country.Code) ? "N/A" : Country.Code)}");
            Console.WriteLine($"Phone Code : {(string.IsNullOrEmpty(Country.PhoneCode) ? "N/A" : Country.PhoneCode)}");
            Console.WriteLine("\n------------------------------------\n");
            Console.WriteLine("\n");
        }

        public static void ReadCountry(ref clsCountry country, string Title = "")
        {

            Console.WriteLine($"{Title}\n");
            Console.Write("Enter Country Name: ");
            string countryName = Console.ReadLine();

            clsCountry existingCountry = clsCountry.Find(countryName);

            while (existingCountry != null && existingCountry.ID != country.ID)
            {
                Console.Write($"\nCountry Name [ {countryName} ] already exists.\nPlease enter a Unique Country Name: ");
                countryName = Console.ReadLine();
                existingCountry = clsCountry.Find(countryName);
            }

            country.CountryName = countryName;

            Console.Write("Enter Code: ");
            country.Code = Console.ReadLine();

            Console.Write("Enter Phone Code: ");
            country.PhoneCode = Console.ReadLine();
            Console.WriteLine("\n");

        }

        static void testFindCountry(int ID)
        {
            clsCountry Country1 = clsCountry.Find(ID);

            if (Country1 != null)
            {
                PrintCountryCard(Country1);
            }
            else
            {
                Console.WriteLine($"\nCountry with ID [ {ID} ] is not found!");
            }

        }

        static void testAddNewCountry()
        {
            clsCountry country = new clsCountry();
            ReadCountry(ref country, "Enter New Country Info");
            if (country.Save())
            {
                Console.WriteLine($"Country Added Successfully with ID = {country.ID}");
                PrintCountryCard(country);
            }
            else
            {
                Console.WriteLine("Country Adding Failed");
            }
        }

        static void testUpdateCountry(int ID)
        {
            clsCountry country = clsCountry.Find(ID);
            if (country != null)
            {
                PrintCountryCard(country);
                ReadCountry(ref country, "Enter Update Country Info");

                PrintCountryCard(country);
                if (country.Save())
                {
                    Console.WriteLine($"Country Updated Successfully");
                    PrintCountryCard(country);
                }
                else
                {
                    Console.WriteLine("Country Updating Failed");
                }
            }
            else
            {
                Console.WriteLine($"\nCountry with ID [ {ID} ] is not found!");
            }
        }

        static void testDeleteCountry(int ID)
        {
            if (clsCountry.IsCountryExist(ID))
            {
                if (clsCountry.DeleteCountry(ID))
                {
                    Console.WriteLine($"Country Deleted Successfully");
                }
                else
                {
                    Console.WriteLine("Country Delete Failed");
                }
            }
            else
            {
                Console.WriteLine($"\nCountry with ID [ {ID} ] is not found!");
            }
        }

        public static void PrintCountryRow(DataRow countryRow)
        {
            string Code = (countryRow["Code"] != DBNull.Value ? countryRow["Code"].ToString() : "N/A");
            string PhoneCode = (countryRow["PhoneCode"] != DBNull.Value ? countryRow["PhoneCode"].ToString() : "N/A");

            Console.WriteLine($"| {countryRow["CountryID"],-4} | {countryRow["CountryName"],-25} | {Code,-4} | {PhoneCode,-10} |");
        }

        static void ListCountries()
        {
            DataTable dataTable = clsCountry.GetAllCountries();

            if (dataTable.Rows.Count > 0)
            {
                // Drawing Table Header
                Console.WriteLine("\n------------------------------------------------------------------------");
                Console.WriteLine($"| {"ID",-4} | {"Country Name",-25} | {"Code",-4} | {"Phone Code",-10} |");
                Console.WriteLine("------------------------------------------------------------------------");

                foreach (DataRow row in dataTable.Rows)
                {
                    PrintCountryRow(row);
                }

                // Drawing Table Footer
                Console.WriteLine("------------------------------------------------------------------------\n");
            }
            else
            {
                Console.WriteLine("No Countries Found.");
            }
        }

        static void testIsCountryExist(int ID)
        {
            if (clsCountry.IsCountryExist(ID))
            {
                Console.WriteLine("Yes, Country is there.");
            }
            else
            {
                Console.WriteLine("No, Country is not there.");
            }
        }


        // Adding Functions To Search with Unique CountryName

        static void testFindCountry(string CountryName)
        {
            clsCountry Country1 = clsCountry.Find(CountryName);

            if (Country1 != null)
            {
                PrintCountryCard(Country1);
            }
            else
            {
                Console.WriteLine($"\nCountry with country name [ {CountryName} ] is not found!");
            }

        }

        static void testIsCountryExist(string CountryName)
        {
            if (clsCountry.IsCountryExist(CountryName))
            {
                Console.WriteLine("Yes, Country is there.");
            }
            else
            {
                Console.WriteLine("No, Country is not there.");
            }
        }


        static void Main(string[] args)
        {
            //testFindContact(6);
            //testAddNewContact();
            //testUpdateContact(2);
            //testDeleteContact(6);
            //ListContacts();
            //testIsContactExist(1);


            //testFindCountry(6);
            //testAddNewCountry();
            //testUpdateCountry(2);
            //testDeleteCountry(3);
            ListCountries();
            //testIsCountryExist(7);

            //testFindCountry("Egypt");
            //testIsCountryExist("Egypt");







            Console.ReadKey();
        }
    }
}
