<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Factories\HasFactory;
use Illuminate\Database\Eloquent\Model;
use App\Models\Student;
use App\Models\Course;

class student_course extends Model
{
    use HasFactory;
    protected $table = 'student_courses';
    public $timestamps = false;

    public function course(){
        return $this->belongsTo(Course::class, 'c_id');
    }

    public function student(){
        return $this->belongsTo(Student::class, 'st_id');
    }
}
