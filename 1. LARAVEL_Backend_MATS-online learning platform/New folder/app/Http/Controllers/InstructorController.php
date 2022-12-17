<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use App\Models\Instructor;
use App\Models\Course;
use App\Models\Topic;
use App\Models\Quiz;
use App\Models\Student;
use App\Models\student_course;
use App\Models\Forum;
use App\Models\Forumcomments;
use App\Models\Users;
use phpDocumentor\Reflection\Types\Null_;

class InstructorController extends Controller
{
  public function __construct()
  {
    $this->middleware('auth.user');
  }

  public function Home(Request $req)
  {
    $username = $req->session()->get('username');
    $instructor = Instructor::where('ins_username', $username)->first();

    session(['userdp' => $instructor->ins_dp]);
    session(['nameuser' => $instructor->ins_name]);
    return view('Instructor.InstructorHome')->with('instructor', $instructor);
  }

  public function CreateCourse()
  {
    return view('Instructor.CreateCourse');
  }

  public function CreateCourseSubmit(Request $req)
  {
    $this->validate(
      $req,
      [
        'c_title' => 'required|max:50|min:3',
        'c_description' => 'required|max:200|min:30',
        'c_price' => 'required|max:6',
        'c_thumbnail' => 'mimes:jpg,png,jpeg,bmp'
      ],
      [
        'c_title.required' => 'Please enter title',

      ]
    );

    if ($req->c_thumbnail) {
      $imagename = $req->c_title . time() . '.' . $req->c_thumbnail->extension();
      $image = $req->c_thumbnail->storeAs('public/coursethumbnail', $imagename);
    }


    $username = $req->session()->get('username');
    $instructor = Instructor::where('ins_username', $username)->first();

    $c = new Course();
    $c->c_title = $req->c_title;
    $c->c_description = $req->c_description;
    $c->c_price = $req->c_price;
    if (isset($image)) {
      $c->c_thumbnail =  $imagename;
    }
    $c->c_status = 'Inactive';
    $c->c_instructor_fk = $instructor->id;
    $c->c_category_fk = $instructor->ins_cat_fk;
    $c->save();

    return redirect()->route('instructor.home');
  }

  public function CreateTopic(Request $req)
  {

    $topic = Topic::where('t_course_fk', decrypt($req->courseid))->get()->last();
    if ($topic == Null) {
      $lastnumber = 0;
    } else {
      $lastnumber = $topic->t_number;
    }

    return view('Instructor.CreateTopic')->with('lastnumber', $lastnumber);
  }

  public function CreateTopicSubmit(Request $req)
  {
    $this->validate(
      $req,
      [

        't_title' => 'required|max:150|min:3',
        't_video' => 'mimes:mp4,mkv',

      ],
      [
        't_title.required' => 'Please enter title',
      ]
    );

    if ($req->t_video) {
      $videoname = $req->t_title . time() . '.' . $req->t_video->extension();
      $video = $req->t_video->storeAs('/storage/lecturevideo/', $videoname);
    }


    $viewingcourse = $req->session()->get('viewingcourse');

    $t = new Topic();
    $t->t_number = $req->t_number;
    $t->t_title = $req->t_title;
    if (isset($video)) {
      $t->t_video =  $videoname;
    }
    $t->t_material = $req->t_material;
    $t->t_course_fk = $viewingcourse;
    $t->save();

    $course = Course::where('id', $viewingcourse)->first();
    return view('Instructor.ViewCourse')->with('course', $course);
  }

  public function Addquiz(Request $req)
  {

    $quiz = Quiz::where('q_topic_fk', decrypt($req->topicid))->get()->last();
    if ($quiz == Null) {
      $lastnumber = 0;
    } else {
      $lastnumber = $quiz->q_quesnumber;
    }
    return view('Instructor.AddQuiz')->with('lastnumber', $lastnumber);
  }


  public function Addquizsubmit(Request $req)
  {
    $this->validate(
      $req,
      [

        'q_ques' => 'required',
        'q_option1' => 'required',
        'q_option2' => 'required',
        'q_option3' => 'required',
        'q_option4' => 'required',
        'q_ans' => 'required'


      ],
      [
        'q_ques.required' => 'Please enter question',
      ]
    );




    $viewingtopic = $req->session()->get('viewingtopic');

    $q = new Quiz();
    $q->q_quesnumber = $req->q_quesnumber;
    $q->q_ques = $req->q_ques;
    $q->q_option1 = $req->q_option1;
    $q->q_option2 = $req->q_option2;
    $q->q_option3 = $req->q_option3;
    $q->q_option4 = $req->q_option4;

    if (($req->q_ans) == "option1") {
      $q->q_ans = $req->q_option1;
    }
    if (($req->q_ans) == "option2") {
      $q->q_ans = $req->q_option2;
    }
    if (($req->q_ans) == "option3") {
      $q->q_ans = $req->q_option3;
    }
    if (($req->q_ans) == "option4") {
      $q->q_ans = $req->q_option4;
    }

    $q->q_topic_fk = $viewingtopic;
    $q->save();

    $topic = Topic::where('id', $viewingtopic)->first();
    return view('Instructor.ViewTopic')->with('topic', $topic);
  }


  public function EditCourse(Request $req)
  {
    session(['viewingcourse' => decrypt($req->courseid)]);
    $course = Course::where('id', decrypt($req->courseid))->first();
    return view('Instructor.EditCourse')->with('course', $course);
  }

  public function EditCourseSubmit(Request $req)
  {

    $this->validate(
      $req,
      [
        'c_title' => 'required|max:50|min:3',
        'c_description' => 'required|max:200|min:30',
        'c_price' => 'required|max:6',
        'c_thumbnail' => 'mimes:jpg,png,jpeg,bmp'

      ],
      [
        'c_title.required' => 'Please enter username',

      ]
    );


    $username = $req->session()->get('username');
    $viewingcourse = $req->session()->get('viewingcourse');
    $instructor = Instructor::where('ins_username', $username)->first();

    $cu = Course::where('id', $viewingcourse)->first();

    $cu->c_title = $req->c_title;
    $cu->c_description = $req->c_description;
    $cu->c_price = $req->c_price;

    if (isset($req->c_thumbnail)) {
      $imagename = $req->c_title . time() . '.' . $req->c_thumbnail->extension();
      $req->c_thumbnail->storeAs('public/coursethumbnail', $imagename);
      $cu->c_thumbnail =  $imagename;
    }


    $cu->c_status = $req->c_status;
    $cu->c_instructor_fk = $instructor->id;
    $cu->c_category_fk = $instructor->ins_cat_fk;
    $cu->save();

    return view('Instructor.ViewCourse')->with('course', $cu);
  }

  public function DeleteCourse(Request $req)
  {
    session(['viewingcourse' => decrypt($req->courseid)]);
    $course = Course::where('id', decrypt($req->courseid))->first();
    return view('Instructor.DeleteCourse')->with('course', $course);
  }

  public function DeleteCourseSubmit(Request $req)
  {
    $cd = Course::where('id', decrypt($req->id))->first();
    $cd->delete();
    return redirect()->route('instructor.home');
  }

  public function ViewCourse(Request $req)
  {
    $course = Course::where('id', decrypt($req->id))->first();
    session(['viewingcourse' => $course->id]);
    return view('Instructor.ViewCourse')->with('course', $course);
  }

  public function ViewTopic(Request $req)
  {
    $topic = Topic::where('id', decrypt($req->id))->first();
    session(['viewingtopic' => $topic->id]);

    return view('Instructor.ViewTopic')->with('topic', $topic);
  }

  public function ViewStudentList(Request $req)
  {

    $course = Course::where('id', decrypt($req->cid))->first();

    return view('Instructor.ViewStudentList')->with('course', $course);
  }

  public function ViewStudentDetails(Request $req)
  {
    $student = Student::where('id', decrypt($req->stid))->first();


    return view('Instructor.ViewStudentDetails')->with('student', $student);
  }

  public function Forum(Request $req)
  {
    $username = $req->session()->get('username');
    $instructor = Instructor::where('ins_username', $username)->first();
    $forum = Forum::orderBy('f_datetime', 'DESC')->get();
    $forumcomments = Forumcomments::orderBy('fc_datetime')->get();


    return view('Instructor.forum')->with('forum', $forum)
      ->with('instructor', $instructor)
      ->with('forumcomments', $forumcomments);
  }

  public function ForumSubmit(Request $req)
  {
    $username = $req->session()->get('username');


    $this->validate(
      $req,
      [
        'f_question' => 'required|max:300|min:8',
        'c_id' => 'required'
      ],
      []
    );

    $instructor = Instructor::where('ins_username', $username)->first();

    $f = new Forum();
    $f->st_id = $req->u_id;
    $f->f_question = $req->f_question;
    $f->c_id = $req->c_id;
    $f->save();
    $forum = Forum::orderBy('f_datetime', 'DESC')->get();
    $forumcomments = Forumcomments::orderBy('fc_datetime')->get();
    return redirect()->route('instructor.forum')->with('forum', $forum)
      ->with('instructor', $instructor)
      ->with('forumcomments', $forumcomments);
  }


  public function ForumCommentSubmit(Request $req)
  {
    $username = $req->session()->get('username');


    $this->validate(
      $req,
      [
        'fc_comment' => 'required|max:250'
      ],
      []
    );

    $instructor = Instructor::where('ins_username', $username)->first();
    $fc = new Forumcomments();
    $fc->fc_uid = $req->u_id;
    $fc->fc_comment = $req->fc_comment;
    $fc->fc_forum_fk = $req->fc_forum_fk;
    $fc->save();

    $forum = Forum::orderBy('f_datetime', 'DESC')->get();
    $forumcomments = Forumcomments::orderBy('fc_datetime')->get();
    return redirect()->route('instructor.forum')->with('forum', $forum)
      ->with('instructor', $instructor)
      ->with('forumcomments', $forumcomments);
  }


  public function EditTopic(Request $req)
  {
    session(['viewingtopic' => decrypt($req->topicid)]);
    $topic = Topic::where('id', decrypt($req->topicid))->first();

    return view('Instructor.EditTopic')->with('topic', $topic);
  }

  public function EditTopicsubmit(Request $req)
  {
    $this->validate(
      $req,
      [
        't_title' => 'required|max:150|min:3',
        't_video' => 'mimes:mp4,mkv',

      ],
      []
    );


    $viewingcourse = $req->session()->get('viewingcourse');
    $viewingtopic = $req->session()->get('viewingtopic');
    $course = Course::where('id', $viewingcourse)->first();

    $t = Topic::where('id', $viewingtopic)->first();

    $t->t_title = $req->t_title;
    $t->t_number = $req->t_number;
    $t->t_material = $req->t_material;


    if ($req->t_video) {
      $videoname = $req->t_title . time() . '.' . $req->t_video->extension();
      $video = $req->t_video->storeAs('public/lecturevideo', $videoname);
    }
    if (isset($video)) {
      $t->t_video =  $videoname;
    }



    $t->t_course_fk = $course->id;
    $t->t_publicviewlock = "no";
    $t->save();

    return redirect()->route('instructor.viewtopic', ['id' => encrypt($t->id)]);
  }


  public function Financial(Request $req)
  {
    $username = $req->session()->get('username');
    $instructor = Instructor::where('ins_username', $username)->first();

    return view('Instructor.Financial')->with('instructor', $instructor);
  }

  public function MyProfile(Request $req)
  {
    $username = $req->session()->get('username');
    $instructor = Instructor::where('ins_username', $username)->first();

    return view('Instructor.MyProfile')->with('instructor', $instructor);
  }

  public function EditProfile(Request $req)
  {

    $instructor = Instructor::where('id', decrypt($req->id))->first();

    return view('Instructor.EditProfile')->with('instructor', $instructor);
  }

  public function EditProfileSubmit(Request $req)
  {
    $this->validate(
      $req,
      [],
      []
    );


    $username = $req->session()->get('username');

    $ins = Instructor::where('ins_username', $username)->first();


    $ins->ins_name = $req->ins_name;
    $ins->ins_username = $req->ins_username;
    $ins->ins_degree = $req->ins_degree;
    $ins->ins_bio = $req->ins_bio;
    $ins->ins_phone = $req->ins_phone;
    $ins->ins_email = $req->ins_email;
    $ins->ins_exp = $req->ins_exp;
    $ins->ins_joindate = $req->ins_joindate;
    if ($req->ins_dp) {
      $imagename = $req->ins_username . time() . '.' . $req->ins_dp->extension();
      $image = $req->t_video->storeAs('storage/dp/instructors', $imagename);
    }
    if (isset($image)) {
      $ins->ins_dp =  $imagename;
    }

    $ins->save();

    return redirect()->route('instructor.profile');
  }
}
