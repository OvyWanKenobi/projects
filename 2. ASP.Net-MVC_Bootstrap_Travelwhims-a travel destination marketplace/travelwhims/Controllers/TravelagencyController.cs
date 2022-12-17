using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using travelwhims.Auth;
using travelwhims.Models.Entities;
using travelwhims.Models.TWdatabase;

namespace travelwhims.Controllers
{

    [AgencyAccess]
    public class TravelagencyController : Controller
    {
        // GET: Travelagency
        public ActionResult Home()
        {
            var id = Session["agencyid"].ToString();
            TWDatabaseEntities db = new TWDatabaseEntities();
            var data = (from p in db.Packages
                        where p.pac_ta_fk.ToString() == id
                        orderby p.pac_tourdate ascending
                        select p).ToList();
            return View(data);
        }

        public ActionResult Package(int id)
        {
            TWDatabaseEntities db = new TWDatabaseEntities();
            var data = (from p in db.Packages
                        where p.id == id
                        select p).FirstOrDefault();

            return View(data);
        }

        [HttpGet]
        public ActionResult MyPackages()
        {
            var id = Session["agencyid"].ToString();
            TWDatabaseEntities db = new TWDatabaseEntities();
            var data = (from p in db.Packages
                        where p.pac_ta_fk.ToString() == id
                        orderby p.pac_tourdate ascending   /*.ToString("yyyyMMdd")*/
                        select p).ToList();

            return View(data);
        }

        [HttpGet]
        public ActionResult CreatePackage()
        {

            return View();
        }

        [HttpPost]
        public ActionResult CreatePackage(Package pac)
        {
            var aid = Convert.ToInt32(Session["agencyid"]);

            if (ModelState.IsValid)
            {

                TWDatabaseEntities db = new TWDatabaseEntities();
                var p = new Package();
                p.pac_title = pac.pac_title;
                p.pac_destinations = pac.pac_destinations;
                p.pac_bio = pac.pac_bio;
                p.pac_price = pac.pac_price;
                p.pac_prerequisite = pac.pac_prerequisite;
                p.pac_status = "Inactive";
                p.pac_maxmember = pac.pac_maxmember;
                p.pac_class = pac.pac_class;
                p.pac_category = pac.pac_category;
                p.pac_tourdate = pac.pac_tourdate;
                p.pac_returndate = pac.pac_returndate;
                p.pac_ta_fk = aid;


                if (pac.pac_thumbnail != null)
                {
                    string filename = Path.GetFileNameWithoutExtension(pac.profilepicture.FileName);
                    string extention = Path.GetExtension(pac.profilepicture.FileName);
                    filename = filename + "-" + DateTime.Now.ToString("yyMMddhhmmss") + extention;
                    p.pac_thumbnail = filename;
                    filename = Path.Combine(Server.MapPath("~/images/packages/"), filename);
                    pac.profilepicture.SaveAs(filename);
                }


                db.Packages.Add(p);
                db.SaveChanges();


                return RedirectToAction("MyPackages");
            }

            return View();

        }

        [HttpGet]
        public ActionResult Participants(int id)
        {
            TWDatabaseEntities db = new TWDatabaseEntities();
            var data = (from p in db.Packages
                        where p.id == id
                        select p).FirstOrDefault();

            var participants = (from par in db.CustomerPackages
                                where par.pac_id == data.id
                                select par).ToList();
            return View(participants);
        }

        [HttpGet]
        public ActionResult EditPackage(int id)
        {
            TWDatabaseEntities db = new TWDatabaseEntities();

            var data = (from p in db.Packages
                        where p.id == id
                        select p).FirstOrDefault();


            return View(data);
        }

        [HttpPost]
        public ActionResult EditPackage(Package pac)
        {
            if (ModelState.IsValid)
            {
                TWDatabaseEntities db = new TWDatabaseEntities();
                var data = (from p in db.Packages
                            where p.id == pac.id
                            select p).FirstOrDefault();



                if (pac.profilepicture != null)
                {
                    string filename = Path.GetFileNameWithoutExtension(pac.profilepicture.FileName);
                    string extention = Path.GetExtension(pac.profilepicture.FileName);
                    filename = filename + "-" + DateTime.Now.ToString("yyMMddhhmmss") + extention;
                    pac.pac_thumbnail = filename;
                    filename = Path.Combine(Server.MapPath("~/images/packages/"), filename);
                    pac.profilepicture.SaveAs(filename);

                }
                else
                {
                    pac.pac_thumbnail = data.pac_thumbnail;
                }

                pac.pac_status = "Inactive";

                db.Entry(data).CurrentValues.SetValues(pac);
                db.SaveChanges();
                return RedirectToAction("MyPackages");

            }
            return View(pac);
        }


        public ActionResult Financial()
        {

            var id = Session["agencyid"].ToString();
            TWDatabaseEntities db = new TWDatabaseEntities();
            var data = (from p in db.Packages
                        where p.pac_ta_fk.ToString() == id
                        select p).ToList();


            return View(data);

        }


        public ActionResult MyProfile()
        {

            var id = Session["agencyid"].ToString();
            TWDatabaseEntities db = new TWDatabaseEntities();
            var data = (from p in db.TravelAgencies
                        where p.id.ToString() == id
                        select p).FirstOrDefault();


            return View(data);
        }

        [HttpGet]
        public ActionResult EditProfile()
        {

            var id = Session["agencyid"].ToString();
            TWDatabaseEntities db = new TWDatabaseEntities();
            var data = (from p in db.TravelAgencies
                        where p.id.ToString() == id
                        select p).FirstOrDefault();


            return View(data);
        }

        [HttpPost]
        public ActionResult EditProfile(TravelAgency ta)
        {

            if (ModelState.IsValid)
            {
                TWDatabaseEntities db = new TWDatabaseEntities();
                var data = (from t in db.TravelAgencies
                            where t.id == ta.id
                            select t).FirstOrDefault();



                if (ta.tadisplaypicture != null)
                {
                    string filename = Path.GetFileNameWithoutExtension(ta.tadisplaypicture.FileName);
                    string extention = Path.GetExtension(ta.tadisplaypicture.FileName);
                    filename = filename + "-" + DateTime.Now.ToString("yyMMddhhmmss") + extention;
                    ta.ta_dp = filename;
                    filename = Path.Combine(Server.MapPath("~/images/travelagencies/"), filename);
                    ta.tadisplaypicture.SaveAs(filename);

                }
                else
                {
                    ta.ta_dp = data.ta_dp;
                }


                db.Entry(data).CurrentValues.SetValues(ta);
                db.SaveChanges();
                return RedirectToAction("MyProfile");

            }
            return View(ta);
        }

        [HttpGet]
        public ActionResult ChangePassword()
        {

          
            return View();
        }

        [HttpPost]
        public ActionResult ChangePassword(ChangePass pass)
        {
            if (ModelState.IsValid)
            {
                var id = Session["Userid"].ToString();
                TWDatabaseEntities db = new TWDatabaseEntities();
                var data = (from u in db.Users
                            where u.id.ToString() == id
                            select u).FirstOrDefault();

                User user = new User();
                user.id = data.id;
                user.u_username = data.u_username;
                user.u_type = data.u_type;

                if (pass.oldpass == data.u_password)
                {
                    if (pass.newpass == pass.confirmpass)
                    {
                        user.u_password = pass.newpass;


                        db.Entry(data).CurrentValues.SetValues(user);
                        db.SaveChanges();
                        return RedirectToAction("MyProfile");
                    }
                }
                 

            }


            return View();
        }
    }
}