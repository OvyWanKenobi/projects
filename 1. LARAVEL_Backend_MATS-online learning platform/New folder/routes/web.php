<?php

use App\Http\Controllers\InstructorController;
use App\Http\Controllers\PublicController;
use Illuminate\Support\Facades\Route;

/*
|--------------------------------------------------------------------------
| Web Routes
|--------------------------------------------------------------------------
|
| Here is where you can register web routes for your application. These
| routes are loaded by the RouteServiceProvider within a group which
| contains the "web" middleware group. Now create something great!
|
*/

Route::get('/',[PublicController::class,'login'])->name('Login');
Route::post('/login',[PublicController::class,'loginsubmit'])->name('Loginsubmit');
Route::get('/logout',[PublicController::class,'logout'])->name('Logout');

Route::get('OurInstructors',[PublicController::class,'InstructorList'])->name('public.instructorlist');
Route::get('OurInstructors/{id}',[PublicController::class,'InstructorDetails'])->name('public.instructordetails');
Route::get('ContactUs',[PublicController::class,'ContactUs'])->name('public.contactus');


Route::get('Instructor',[InstructorController::class,'Home'])->name('instructor.home');
Route::get('Instructor/createcourse',[InstructorController::class,'CreateCourse'])->name('instructor.createcourse');
Route::post('Instructor/createcourse',[InstructorController::class,'CreateCourseSubmit'])->name('instructor.createcoursesubmit');
Route::get('Instructor/createtopic/{courseid}',[InstructorController::class,'CreateTopic'])->name('instructor.createtopic');
Route::post('Instructor/createcoursetopic',[InstructorController::class,'CreateTopicSubmit'])->name('instructor.createtopicsubmit');
Route::get('Instructor/viewcourse/{id}',[InstructorController::class,'ViewCourse'])->name('instructor.viewcourse');
Route::get('Instructor/topic/{id}',[InstructorController::class,'ViewTopic'])->name('instructor.viewtopic');
Route::get('Instructor/topic/{topicid}/addquiz',[InstructorController::class,'Addquiz'])->name('instructor.addquiz');
Route::post('Instructor/topic/addquiz',[InstructorController::class,'Addquizsubmit'])->name('instructor.addquizsubmit');
Route::get('Instructor/course/{cid}/students',[InstructorController::class,'ViewStudentList'])->name('instructor.coursestudentlist');
Route::get('Instructor/course/students/{stid}',[InstructorController::class,'ViewStudentDetails'])->name('instructor.studentdetails');
Route::get('Instructor/course/forum',[InstructorController::class,'Forum'])->name('instructor.forum');
Route::post('Instructor/course/forums',[InstructorController::class,'ForumSubmit'])->name('instructor.forumsubmit');
Route::post('Instructor/course/forumcs',[InstructorController::class,'ForumCommentSubmit'])->name('instructor.forumcommentsubmit');

Route::get('Instructor/editcourse',[InstructorController::class,'EditCourse'])->name('instructor.editcourse');
Route::post('Instructor/editcourse',[InstructorController::class,'EditCourseSubmit'])->name('instructor.editcoursesubmit');
Route::get('Instructor/edittopic',[InstructorController::class,'EditTopic'])->name('instructor.edittopic');
Route::post('Instructor/edittopic',[InstructorController::class,'EditTopicSubmit'])->name('instructor.edittopicsubmit');

Route::get('Instructor/deletecourse',[InstructorController::class,'DeleteCourse'])->name('instructor.deletecourse');
Route::get('Instructor/deletecourse/{id}',[InstructorController::class,'DeleteCourseSubmit'])->name('instructor.deletecoursesubmit');

Route::get('Instructor/financial',[InstructorController::class,'Financial'])->name('instructor.financial');
Route::get('Instructor/profile',[InstructorController::class,'MyProfile'])->name('instructor.profile');
Route::get('Instructor/editprofile/{id}',[InstructorController::class,'EditProfile'])->name('instructor.editprofile');
Route::post('Instructor/editprofile',[InstructorController::class,'EditProfileSubmit'])->name('instructor.editprofilesubmit');