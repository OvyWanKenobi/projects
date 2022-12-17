<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Factories\HasFactory;
use Illuminate\Database\Eloquent\Model;
use App\Models\Instructor;
use App\Models\student_course;
use App\Models\Rating;
use App\Models\Topic;

class Course extends Model
{
    use HasFactory;

    protected $table = 'courses';
    public $timestamps = false;

    public function instructorofcourse(){
        return $this->belongsTo(Instructor::class,'c_instructor_fk');
    }

    public function studentsincourse(){
        return $this->hasMany(student_course::class,'c_id');
    }

    public function ratingsofcourse(){
        return $this->hasMany(Rating::class,'c_id');
    }

    public function topics(){
        return $this->hasMany(Topic::class,'t_course_fk');
    }

    public function forums(){
        return $this->hasMany(Topic::class,'c_id');
    }


}
