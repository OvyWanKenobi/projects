using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using System.Web.Security;
using travelwhims.Models.Entities;
using travelwhims.Models.TWdatabase;

namespace travelwhims.Controllers
{
    [AllowAnonymous]
    public class PublicController : Controller
    {
        // GET: Public

        [HttpGet]
        public ActionResult Index()
        {
            TWDatabaseEntities db = new TWDatabaseEntities();
            var data = (from p in db.Packages
                        where p.pac_status != "Inactive"
                        select p).ToList();

            return View(data);
        }

        [HttpGet]
        public ActionResult Packages()
        {
            TWDatabaseEntities db = new TWDatabaseEntities();
            var data = (from p in db.Packages
                        where p.pac_status != "Inactive"
                        select p).ToList();

            return View(data);
        }

        [HttpGet]
        public ActionResult Package(int id)
        {
            TWDatabaseEntities db = new TWDatabaseEntities();
            var data = (from p in db.Packages 
                        where p.id == id 
                        select p).FirstOrDefault();

            return View(data);
        }

        public ActionResult TravelAgency(int id)
        {
            TWDatabaseEntities db = new TWDatabaseEntities();
            var data = (from ta in db.TravelAgencies
                        where ta.id == id
                        select ta).FirstOrDefault();

            return View(data);
        }

        public ActionResult TravelAgencies()
        {
            TWDatabaseEntities db = new TWDatabaseEntities();
            var data1 = (from ta in db.TravelAgencies
                         where ta.ta_rating != "notrated"
                        orderby ta.ta_rating ascending
                        select ta).ToList();
            var data2 = (from ta in db.TravelAgencies
                         where ta.ta_rating == "notrated"
                         select ta).ToList();
            data1.AddRange(data2);

            return View(data1);
        }

        [HttpGet]
        public ActionResult Signup()
        {
            return View();
        }

        [HttpPost]
        public ActionResult Signup(CustomerModel newuser )
        {
            if (ModelState.IsValid)
            {

                TWDatabaseEntities db = new TWDatabaseEntities();

                var data = (from un in db.Users
                            where un.u_username.Equals(newuser.c_username)
                            select un).FirstOrDefault();
              
                if (data.u_username.Count() > 0)
                {
                    TempData["msg"] = "Username Taken";
                    return View(newuser);
                }


                var c = new Customer();
                c.c_name = newuser.c_name;
                c.c_username = newuser.c_username;
                c.c_phone = newuser.c_phone;
                c.c_address = newuser.c_address;
                c.c_mail = newuser.c_mail;

                string filename = Path.GetFileNameWithoutExtension(newuser.profilepicture.FileName);
                string extention = Path.GetExtension(newuser.profilepicture.FileName);
                filename = filename + "-" + DateTime.Now.ToString("yyMMddhhmmss") + extention;
                c.c_dp = filename;
                filename = Path.Combine(Server.MapPath("~/images/customers/"), filename);
                newuser.profilepicture.SaveAs(filename);

                db.Customers.Add(c);
                db.SaveChanges();

                var u = new User();
                u.u_username = newuser.c_username;
                u.u_password = newuser.u_password;
                u.u_type = "customer";
                db.Users.Add(u);
                db.SaveChanges();


                TempData["msg"] = "Registration Successful";

                return RedirectToAction("Login");
            }
            
           

            return View();
        }


        [HttpGet]
        public ActionResult Login()
        {
            return View();
        }

        [HttpPost]
        public ActionResult Login(User user)
        {
            TWDatabaseEntities db = new TWDatabaseEntities();
            var data= (from u in db.Users
                      where u.u_password.Equals(user.u_password) &&
                      u.u_username.Equals(user.u_username)
                      select u).FirstOrDefault();


            if(data != null)
            {
                Session["Username"] = data.u_username;
                Session["UserType"] = data.u_type;
                Session["Userid"] = data.id;

                if (data.u_type == "admin")
                {
                    return RedirectToAction("Home", "Admin");
                }
                if (data.u_type == "customer")
                {
                    return RedirectToAction("Home", "Customer");
                }
                if (data.u_type == "agency")
                {
                    var data2 = (from ta in db.TravelAgencies
                                 where ta.ta_username.Equals(data.u_username)
                                 select ta).FirstOrDefault();
                    Session["agencyname"] = data2.ta_name;
                    Session["agencyid"] = data2.id;
                    Session["propic"] = data2.ta_dp;

                    FormsAuthentication.SetAuthCookie(data.u_type, false);


                    var dd = Session["agencyid"];
                    
                    return RedirectToAction("Home", "Travelagency");
                }
                if (data.u_type == "manager")
                {
                    return RedirectToAction("Home", "Manager");
                }
            }

            TempData["msg"] = "Invalid Credentials";
            return RedirectToAction("Login");

        }

        [HttpGet]
        public ActionResult Logout()
        {
            FormsAuthentication.SignOut(); 
            return RedirectToAction("Login");
        }

        [HttpGet]
        public ActionResult AgencyRegister()
        {

            return View();
        }


        [HttpPost]
        public ActionResult AgencyRegister(AgencyModel newta)
        {
            if (ModelState.IsValid)
            {

                TWDatabaseEntities db = new TWDatabaseEntities();
                var data = (from un in db.Users
                            where un.u_username.Equals(newta.ta_username) 
                            select un).FirstOrDefault();

                if (data.u_username.Count() > 0)
                {
                    TempData["msg"] = "Username Taken";
                    return View(newta);
                }


                var ta = new TravelAgency();
                ta.ta_name = newta.ta_name;
                ta.ta_username = newta.ta_username;
                ta.ta_bio = newta.ta_bio;
                ta.ta_mail = newta.ta_mail;
                ta.ta_officeaddress = newta.ta_officeaddress;
                ta.ta_phone = newta.ta_phone;
                ta.ta_rating = "notrated";
               

                string filename = Path.GetFileNameWithoutExtension(newta.tadisplaypicture.FileName);
                string extention = Path.GetExtension(newta.tadisplaypicture.FileName);
                filename = filename + "-" + DateTime.Now.ToString("yyMMddhhmmss") + extention;
                ta.ta_dp = filename;
                filename = Path.Combine(Server.MapPath("~/images/travelagencies/"), filename);
                newta.tadisplaypicture.SaveAs(filename);

                db.TravelAgencies.Add(ta);
                db.SaveChanges();

                var u = new User();
                u.u_username = newta.ta_username;
                u.u_password = newta.u_password;
                u.u_type = "agency";
                db.Users.Add(u);
                db.SaveChanges();


                TempData["msg"] = "Your Agency is enlisted in our website";

                return RedirectToAction("TravelAgencies");
            }


            return View(newta);
        }


    }
}